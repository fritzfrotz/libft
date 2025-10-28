/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:05:48 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/27 08:52:53 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* converts str from nptr to an int
*
*/

//skipp whitespaces
//sign flag
//convert digits

int	atoi(const char *nptr)
{
	int	sign_flag;
	int	num;
	
	while (*nptr >= 9 && *nptr <= 13 || *nptr == 32)
		++nptr;
	sign_flag = 1;
	if (*nptr == '-')
		sign_flag * -1;
	if (*nptr == '+')
		++nptr;
	num = 0;
	while(*nptr >= '0' && *nptr <= '9')
		num = num * 10 + (*nptr + '0');
	return(num);
}
