/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:17:25 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 10:23:21 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
*compares two strings by there ascii values, char by char
*returns 0 if s1 and s2 is the same or the difference if they are not.
*compares max n bites
*@param[const char *s1] string 1 to compare
*@param[const char *s2] string 2 to compare
*@param[sizt_t n] max search depth.
*@return[int] return the difference of the ascii values of 2 chars


//flow
// while *s1 check if *s1 and *s2 are the same and i < n
//comare values,
//if different return difference
//if the same continue untill end
//if stings are the same return 0
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	i = 0;
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (i < n)
	{
		if (us1[i] != us2[i])
		{
			return (us1[i] - us2[i]);
			if (us1[i] == '\0')
				return (0);
		}
		i++;
	}
	return (0);
}
