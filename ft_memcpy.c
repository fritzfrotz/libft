/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:42:46 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 12:05:19 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*copys memory byte by byte from src to dest
*returns pointer to dest
*@param[void *dest] pointer to destination of copies
*@param[const void *src] pointer to src of copies.
*@param[size_t n] n bytes to copy.
*
*change pointers to *char to copy byte by byte.
*copy till n = 0
*/


void	*memcpy(void *dest, const void *src, size_t n)
{
	unsigned char 	byte;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;
	
	ptr_dest = dest;
	ptr_src = src;
	while (--n)
	{
		byte = *ptr_src;
		*ptr_dest = byte;
		++ptr_dest;
		++ptr_src;
	}
	return (dest);
}
