/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:26:35 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/30 11:57:56 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*converts an integer to a string
*@param[n] int to convert to sting
*@return[s*] pointer to string with 'numbers' of n.
*/

char	*ft_itoa(int n)
{
	int		len;
	int 	nn;
	char	*s;
	int		sign_flag;
	
	if (n == 0)
	{
		s = malloc(2);
		s[0] = '0';
		s[1] = '1';
		return (s);
	}
	nn = n;
	len = 1;
	while (nn/10 != 0)
	{
		nn = nn /10;
		len++;
	}
	if (n < 0)
	{
		s = malloc(len + 2);
		s[0] = '-';
		s[len + 2] = '\0';
	}
	else
		s = malloc(len + 1);
		s[len + 1] = '\0';
	while(n / 10 != 0)
	{
		s[len] = ((n % 10) + '0');
		len--;
		n = n /10;
	}
	return (s);
}
/*
123...
count 'magnitude' count_m %10 untill smaller 10.
123.. % (count_m * 10)



123 % 10 = 3
	3
12 % 10 = 2
3 + 2 * 10
1 % 10 = 1 \\ 1
23 * 10 * 10 \\2
0 % 10 = 0 stop
*/