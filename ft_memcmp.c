/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 14:16:38 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 14:49:00 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*compares two memory reagions, returns integer dependent of the results.
*substracts *s1 from *s2, if value != 0 returns it.
*if n is zerro the return value is 0;
*@param[s1] memory area 1
*@param[s2] memry area 2
*@param[n] bites to 
*@return negative if ascii value of *s2 bigger,
*		 positive if ascii value of *s1 bigger,
*		 0 if momories are the same
*/
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n){
	unsigned char	*c1;
	unsigned char	*c2;
	
	c1 = s1;
	c2 = s2;
	while (n--)
		if ( *c1 != *c2)
			return(*c1 - *c2);
		c1++;
		c2++;
	return(0);
}
