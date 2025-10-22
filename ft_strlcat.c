/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 10:19:37 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/22 13:40:40 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	strlcat(char	*dst, const char	*src, size_t	size)
{
	size_t	dst_len;
	size_t src_len;
	size_t	i;
	
	dst_len = 0;
	while (dst[dst_len])
	{
		++dst_len;
	}
	src_len = 0;
	while(src[src_len]) 
	{
		++src_len;
	}
	if (dst_len >= size)
		return ((size + src_len));
	i = 0;
	while (src[i] && (dst_len + i) < (size -1))
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return(src_len + dst_len);
}