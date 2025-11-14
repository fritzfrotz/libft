/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:51:48 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/14 08:54:03 by fhollman         ###   ########.fr       */
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

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	e;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && char_in_set(s1[i], set))
		i++;
	e = ft_strlen(s1);
	while (e > i && char_in_set(s1[e - 1], set))
		e--;
	return (ft_substr(s1, i, e - i));
}
