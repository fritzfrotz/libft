/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:44:03 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 12:19:52 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*copies bytes from src to dest, area may overlap.
*@param[void * dest] destination memmory
*@param[const void *src] copy bytes from source.
*@param[size_t n] bytes to copy

//unsignet char to write and read single bytes.
//count src
//
//move src to tmp
//write from tmp tp dest
//return pt to dest.
*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d == NULL && s == NULL)
		return (NULL);
	if (d == s || n == 0)
		return (dest);
	if (d > s)
		dest_bigger(d, s, n);
	else
		dest_smaller();
	return (dest);
}

void	dest_bigger(d, s, n)
{
	while (n > 0)
	{
		n--;
		d[n] = s[n];
	}
}
void	dest_smaller(i, n, d, s)
{
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}