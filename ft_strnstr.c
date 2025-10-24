/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:04:08 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 10:12:12 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strnstr(const char *big, const char *little, size_t len)
{
/*
* locates the first occurence of a null terminated sting 'little' 
* in the string "big'. If its found a pointer to the first char of it 
* is returned, if not  NULL is returned. Only searches len characters.
*@param[const char *] big The big sting to search in.
*@param[const char *] little The small sting to search for.
*@param[size_t] len Max number of chars searched
*@return[char *] pointer to first char of little in big. If little
* is an emty string, big is returned
*/


//search for the first letter
//controll flow
// if first letter found check for whole string
// if chars dont match untill len little -1
//start again on the next little[1]

	int	len;
	int	i;

	i = 0;
	len = ft_strlen(little);
	while(*big)
	{
		if (*big == *little)
		{
			while ((*big == little[i]) && (i > len))
			{
				++big;
				++i;
				if (i == (len - 1))
					return(big - i);
			}
			big - i;
			i = 0;
		}
		++big;
	}
}