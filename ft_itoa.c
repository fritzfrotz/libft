/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 10:26:35 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/14 08:54:49 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*converts an integer to a string
*@param[n] int to convert to sting
*@return[s*] pointer to string with 'numbers' of n.
*/

#include "libft.h"

static int	get_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_fill_str(char *s, long nbr, int len)
{
	s[len] = '\0';
	len--;
	if (nbr == 0)
	{
		s[0] = '0';
		return ;
	}
	if (nbr < 0)
	{
		s[0] = '-';
		nbr = -nbr;
	}
	while (nbr > 0)
	{
		s[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	long	nbr;

	nbr = n;
	len = get_len(nbr);
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	ft_fill_str(s, nbr, len);
	return (s);
}
