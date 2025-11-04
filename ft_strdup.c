/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 10:30:42 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/04 15:56:36 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s_return;
	size_t	len;

	len = ft_strlen(s1);
	s_return = (char *)malloc(len + 1);
	if (s_return == NULL)
		return (NULL);
	ft_memcpy(s_return, s1, len + 1);
	return (s_return);
}
