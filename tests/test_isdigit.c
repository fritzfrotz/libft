/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	test_isdigit(void)
{
	int	n = -2;
	printf("Testing isdigit... ");
	while (++n < 256)
	{
		if (!!ft_isdigit(n) != !!isdigit(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}