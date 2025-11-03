#include "libft.h"
#include <ctype.h>
#include <stdio.h>

/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/

int	test_isprint(void)
{
	int	n = -2;
	printf("Testing isprint...");
	while (++n < 256)
	{
		if (!!ft_isprint(n) != !!isprint(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}