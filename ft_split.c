/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:01:37 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/30 10:07:25 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*split a string at c, return array of new stsrings
*@param[*s] string to split.
*@param[c] delimiter to split at.
*return[**arr] array of 0 terminated strings.
*/

#include "libft.h"

char **ft_split(char const *s, char c)
{
	/* allocate memory for the pointers to eachs string + NULL*/
	
	/*count chars and allocate momory for each string + '\0'
	*copy string
	*add '\0'
	*/
	char	**arr;

	arr = malloc_array(s, c);
	malloc_strings(arr, s, c);
	cpy_strings(arr, s, c);
	return (arr);
	

}

int	count_words(char *s, char c)
{
	int	word_count;

	while (*s)
	{
		while (*s == c)
			s++;
		word_count =+ 1;
		while (*s != c)
			s++;
	}
	return word_count;
}

char	**malloc_array(unsigned char *s, char c)
{
	int	word_count;
	char	**arr;
	
	word_count = count_words(s, c);
	arr = malloc(word_count * sizeof(char *));
	return (arr);
}

void	malloc_strings(char **arr, char *s,char c)
{
	int	i;
	int e;
	int j;
	int	char_in_word;
	
	i = 0;
	e = 0;
	j = 0;
	char_in_word = 0;
	while(*arr[i] != NULL)
	{
		while (s[e] != c)
		{
			char_in_word++;
			e++;
		}
		e++;
		arr[i][j] = malloc(char_in_word);
		char_in_word = 0;
		i++;
		j++;
	}
}

void	cpy_strings(char **arr, char *s,char c)
{
	int	i;
	int e;
	int j;
	
	i = 0;
	e = 0;
	j = 0;
	while(*arr[i] != NULL)
	{
		while (s[e] != c)
		{
			arr[i][j] = s[e];
			e++;
			j++;
		}
		arr[i][j] = '\0';
		e++;
		i++;
	}
}
