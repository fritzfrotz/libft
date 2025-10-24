/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 10:08:49 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 14:50:30 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memset(void *s, int c, size_t n)
{
/*
*fills n bites of memory pointet to by s with c.
*using siged char to tuncate int to char.
*@param[void *s] memory to copy c to 
*@param[int c] int to copy in memory of s
*@param[size_t n] n nites to write.
*@return[void *] returns pointer to s
*/
// truncate int c because int 4 bytes and char 1 byte
//just write over the mem until n is reached.
//give pointer to mem back.

	unsigned char	*ptr;
	unsigned char	byte;

	byte = c;
	ptr = s;
	while(--n)
	{
		*ptr = byte;
	}
	return (s);
}
 