/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbook2025 <macbook2025@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 12:02:01 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/11 09:18:04 by macbook2025      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*applies a function f to each char in s.
*@param[f] pointer to function
*@param[s] og sting
*	@param[int] index of og sting
*	@param[char] actual char in string
*@return pointer to mapped string
*/

#include "libft.h"

static void	function(char const *s, char *return_s, char (*f)(unsigned int, char))
{
	unsigned int	index;

	index = 0;
	while (*s)
	{
		*return_s = f(index, *s);
		return_s++;
		s++;
		index++;
	}
	*return_s = '\0';
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	char	*return_s;

	if ((s == NULL) || (f == NULL))
		return (NULL);
	len = ft_strlen(s);
	return_s = malloc(len + 1);
	if (return_s == NULL)
		return (NULL);
	function(s, return_s, f);
	return (return_s);
}