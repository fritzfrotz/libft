/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:04:08 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/04 10:30:04 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{

	size_t	i;
	size_t	e;
	size_t	len_l;
	
	len_l = ft_strlen(little);
	if (len_l == 0)
		return((char*)big);
	i = 0;
		while(big[i] != '\0' && i < len)
	{
		e = 0;
		while ((i + e) < len && little[e] != '\0' && big[i + e] == little[e])
			e++;
		if (e == len_l)
			return (char*)&big[i];
	i++;
	}
	return (NULL);
}