/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 08:01:37 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 11:29:48 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*split a string at c, return array of new stsrings
*@param[*s] string to split.
*@param[c] delimiter to split at.
*return[**arr] array of 0 terminated strings.
*/

#include "libft.h"

static char	**ft_free_array(char **array, size_t i)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (NULL);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static size_t	ft_get_word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	word_count;
	size_t	i;
	size_t	word_len;

	if (!s)
		return (NULL);
	word_count = ft_count_words(s, c);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		word_len = ft_get_word_len(s, c);
		array[i] = ft_substr(s, 0, word_len);
		if (!array[i])
			return (ft_free_array(array, i));
		s += word_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}
