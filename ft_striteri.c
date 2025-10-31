/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 06:33:06 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/31 07:12:44 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*takes a string and changes the og string with the funcutoin f
*@param[s] og sting to be mapped;
*@param[f] function to change the sting
*	@param[int] index of char in string
*	@param[char] pointer to char to be mapped
*/

#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	if ((s == NULL) || (f == NULL))
		return;
	function(s, f);
}
void	function(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	index;
	
	index = 0;
	while (s[index] != '\0')
	{
		f(index, &s[index]);
		index++;
	}
}