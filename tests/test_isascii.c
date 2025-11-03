#include "libft.h"
#include <ctype.h>
#include <stdio.h>

/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

int	test_isascii(void)
{
	int	n = -2;
	printf("Testing isascii...");
	while (++n < 256)
	{
		if (!!ft_isascii(n) != !!isascii(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}