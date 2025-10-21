/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stlcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 08:02:22 by fhollman          #+#    #+#             */
/*   Updated: 2025/10/21 09:42:56 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	strlcpy(char	*dest, char	*src, size_t	size)
{
	size_t	len_src;
	size_t	len_dest;

	len_src = 0;
	len_dest = 0;
	while (src[len_src])
		++len_src;
	if (len_src > size)
		return (len_src);
	while (src[len_src])
		{
			dest[len_dest] = dest[len_dest];
			++len_dest;
		}
	dest + len_src + 1 = '\0';
}