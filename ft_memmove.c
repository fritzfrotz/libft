/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:44:03 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/05 08:56:40 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*copies bytes from src to dest, area may overlap.
*uses temp array, then writes.
*@param[void * dest] destination memmory
*@param[const void *src] copy bytes from source.
*@param[size_t n] bytes to copy
*/
//unsignet char to write and read single bytes.
//count src
//init tmp memory
//move src to tmp
//write from tmp tp dest
//return pt to dest.
#include "libft.h"

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *)dest;
	s = (const unsigned char *)src;

	if (d == NULL && s == NULL)
		return (NULL);

	if (d == s || n == 0)
		return (dest);

	if (d > s)
	{
		while (n > 0)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		size_t i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}