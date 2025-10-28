/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_subst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 11:16:27 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/28 08:18:27 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*returns substring from string s. start at start with size len.
*@param[*s] main string
*@params[start] start of substr
*@params[len] len of substr
*/


//count len s
//if len s < start-> NULL
//if len = 0 -> NULL
//if s = NUL -> NULL
// allocate memory: len_s - (start + len) bytes
//copy from s[start] len bytes. 0 terminate

#include "libft.h"
void	malloc_helper(char *s);

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*return_s;
	signed	i;
	
	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		{
		return_s = malloc(1);
		if (!return_s)
			return (NULL);
		return_s[0] = '\0';
		return(return_s);
		}
	if (len == 0)
		return NULL;

	return_s = malloc(len + 1);
	if (!return_s)
		return (NULL);
	s += start;
	while (len < i)
		return_s[i] = s[i];
		i++;
	return_s[i] = '\0';
}