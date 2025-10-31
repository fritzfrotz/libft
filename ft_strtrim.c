/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:51:48 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/28 16:42:49 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*trims string s1 on both end from chars in set
*@param[s1]	string to trim
*@param[set]	char to strip
*@return	stripped string
*/

//while loop


#include "libft.h"

char *ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	e;
	int	j;
	int	total_len;
	char	*return_s;
	
	total_len = ft_strlen(s1);
	i=0;
	while (char_in_set(s1[i], set))
		i++;
	e = total_len - 1;
	while (char_in_set(s1[e], set))
		e--;
	total_len = e - i + 1;
	if (total_len == 0)
		return(return_nt());
	return_s = malloc(total_len + 1);
	if (!return_s)
		return(NULL);
	while (j < (total_len))
	{
		return_s[j] = s1[i + j];
		j++;
	}
	return_s[i] = '\0';
	return(return_s);
}

static int	char_in_set(char c, char const *set)
{
	//loop through s
	//stop at s is not in set / return from strrchr(set) is not true
	//loop through set
	int	i;
	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*return_nt(void)
{
	char	*return_s;
	
	return_s = malloc(1);
	if (!return_s)
		return(NULL);
	return_s[0] = '\0';
	return (return_s);
}

