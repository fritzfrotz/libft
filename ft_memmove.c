/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhollman <fhollman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 12:44:03 by fhollman          #+#    #+#             */
/*   Updated: 2025/11/03 15:26:54 by fhollman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*copies bytes from src to dest, area may overlap.
*uses temp array, then writes.
*@param[void * dest] destination memmory
*@param[const void *src] copy bytes from source.
*@param[size_t n] bytes to copy
*/
//unsignet char to write and read single bytes.
//count src
//init tmp memory
//move src to tmp
//write from tmp tp dest
//return pt to dest.
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	unsigned char	*temp;
	size_t	n_save;
	
	d = dest;
	s = src;
	temp = malloc(n);
	if (!temp)
		return (NULL);
	n_save = n;
	while(n--)
	{
		*temp = *s;
		++temp;
		++s;
	}
	temp -= n_save;
	n = n_save;
	while(n--)
	{
		*d = *temp;
		++d;
		++temp;
	}
	free(temp);
	return (dest-n_save);
}


#include "stdio.h"





/*
typedef struct s_test_case
{
	char	*input;
	size_t		expected;
	char	*desciption;
}	t_test_case;

int	test_memmove(void)
{
	t_test_case test[] = {
		{"hello", 5, "string 'hello'"},
		{"", 0, "empty string"},
		{"a", 1, "one char"},
		{"\n", 1, "new line"},
		{"hello\tworld", 11, "text with tab"},
		{NULL, 0, NULL}
	};
	int i = 0;
	size_t result;
	printf("testing ft_memmove...\n");
	while (test[i].input != NULL)
	{
		result = ft_memmove(test[i].input);
		if (result == memmove(test[i].input))
			printf("%s, " , test[i].desciption);
		else
		{
			printf("fail at %s, got %zu, expeected %zu", test[i].desciption, result, test[i].expected);
		return (1);
		}
		++i;
	}
	printf("\ntests completed\n");
	return (0);
}
*\