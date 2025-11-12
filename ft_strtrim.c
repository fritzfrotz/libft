/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:51:48 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 11:40:43 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*trims string s1 on both end from chars in set
*@param[s1]	string to trim
*@param[set]	char to strip
*@return	stripped string
*/

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	if (!set)
		return (0);
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
		return (NULL);
	return_s[0] = '\0';
	return (return_s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		e;
	int		j;
	int		total_len;
	char	*return_s;

	if (!s1)
		return (NULL);
	total_len = ft_strlen(s1);
	i = 0;
	while (s1[i] && char_in_set(s1[i], set))
		i++;
	e = total_len - 1;
	while (e >= 0 && char_in_set(s1[e], set))
		e--;
	if (i > e)
		return (return_nt());
	total_len = e - i + 1;
	return_s = malloc(total_len + 1);
	if (!return_s)
		return (NULL);
	j = 0;
	while (j < total_len)
	{
		return_s[j] = s1[i + j];
		j++;
	}
	return_s[j] = '\0';
	return (return_s);
}
