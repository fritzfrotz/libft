/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook2025 <macbook2025@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:16:27 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/13 19:31:15 by macbook2025      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*returns substring from string s. start at start with size len.
*@param[*s] main string
*@params[start] start of substr
*@params[len] len of substr
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	real_len;
	char	*sub;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = (char *)malloc(1);
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > s_len - start)
		real_len = s_len - start;
	else
		real_len = len;
	sub = (char *)malloc(real_len + 1);
	if (sub == NULL)
		return (NULL);
	ft_memcpy(sub, s + start, real_len);
	sub[real_len] = '\0';
	return (sub);
}
