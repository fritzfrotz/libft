/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:30:42 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/27 11:15:00 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *strdup(const char *s);
{
	size_t	len;
	size_t	s_return;
	size_t	i;
	
	len = ft_strlen(s);
	s_return = malloc(len);
	if (s_return == NULL)
		return (NULL);
	while (i < len)
		s_return++ = s++;
	return (s_return - len);
}
