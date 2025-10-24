/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:05:48 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 15:34:13 by fhollman         ###   ########.fr       */
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
	
	num = 0;
	sign_flag = 1;
	if (*nptr == '-')
		sign_flag * -1;
	if (*nptr == '+')
		++nptr;
	while(*nptr)
	{
		num += (npr)
	}
	
}
