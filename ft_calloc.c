/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook2025 <macbook2025@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 11:00:24 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/12 17:31:52 by macbook2025      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*mem for arry size nmemb * size, init with 0
*@param[nmemb] size of array member
*@param[size] number of elements in arr
*@return[] 
*/
#include "libft.h"

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total_size;

	if (nmemb == 0 || size == 0)
	{
		mem = malloc(1);
		if (mem == NULL)
			return (NULL);
		ft_bzero(mem, 1);
		return (mem);
	}
	total_size = nmemb * size;
	if (nmemb > (total_size / size))
		return (NULL);
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, total_size);
	return (mem);
}
