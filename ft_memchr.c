/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:02:24 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/04 15:39:00 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*look for the first occurance of c at in memmory s, max bytes n.
*return a pointer to the matching byte or NULL
*@param[const void *s] pointer to memory
*@param[int c] byte to find
*@param[size_t n]
*@return[void *] pinter to memory
*/

#include "libft.h"

void    *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   *ptr;
    unsigned char   char_c;
    
    ptr = (unsigned char *)s;
    char_c = (unsigned char)c;
    while (n--)
    {
        if (*ptr == char_c)
        {
            return ((void *)ptr);
        }
        ptr++;
    }
    return (NULL);
}