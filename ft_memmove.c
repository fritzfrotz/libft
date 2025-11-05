/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:44:03 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/05 08:33:18 by fhollman         ###   ########.fr       */
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	*temp;
	size_t	n_save;
	
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	temp = malloc(n);
	if (!temp)
		return (NULL);
	n_save = n;
	while(n--)
	{
		*temp = *s;
		temp++;
		s++;
	}
	temp -= n_save;
	n = n_save;
	while(n--)
	{
		*d = *temp;
		d++;
		temp++;
	}
	free(temp);
	return (dest-n_save);
}