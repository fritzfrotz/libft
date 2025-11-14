/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:25:12 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/14 08:54:22 by fhollman         ###   ########.fr       */
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
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, s1, len_s1);
	ft_memcpy(new_str + len_s1, s2, len_s2);
	new_str[len_s1 + len_s2] = '\0';
	return (new_str);
}
