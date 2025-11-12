/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:42:46 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 11:08:57 by fhollman         ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	byte;
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;

	if (!dest || !src)
		return (NULL);
	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	while (n--)
	{
		byte = *ptr_src;
		*ptr_dest = byte;
		ptr_dest++;
		ptr_src++;
	}
	return (dest);
}
