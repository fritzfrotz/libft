/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook2025 <macbook2025@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 07:36:08 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/11 11:47:46 by macbook2025      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*
*123 %10 = 3
*
*
*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;
	
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return;
	}
	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	ft_putchar_fd(c, fd);
}