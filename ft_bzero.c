/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:27:39 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/24 11:39:01 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	bzero(void *s, size_t n){
	
/*
*writes n bites with '\0' terminator in mem pointet to by s
*@param[void *s] Pointes to the memory to be written over.
*@param[size_t n] n bytes to write.
*/
	memset(s, '\0', n);
}
