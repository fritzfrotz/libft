/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 07:31:03 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/04 09:49:05 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*returns pointer to last occurence of char in string
*@param[s] string to search in
*@param[c] char to search
*@return	pointer to last char
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	
	r = NULL;
	while (*s != '\0')
		{
		if (*s == (char)c)
			r = (char*)s;
		s++;
		}
	if (*s == (char)c)
		return (char*)s;
	return (r);
}