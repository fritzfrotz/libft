/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:25:12 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 11:46:52 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*gets total number of char = strlen(s1) + strlen(s2)
*gets memory with malloc(total_len)
*writes both strings in return string
*@param[s1] first string
*@param[s2] second string
*@return new return string with s1, s2 concat.
*/
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		q;
	char	*return_s;
	int		len_s1;
	int		len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return_s = malloc(len_s1 + len_s2 + 1);
	if (!return_s)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		return_s[i] = s1[i];
		i++;
	}
	q = 0;
	while (q < len_s2)
	{
		return_s[i + q] = s2[q];
		q++;
	}
	return_s[i + q] = '\0';
	return (return_s);
}
