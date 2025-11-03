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

int	test_isalnum(void)
{
	int	n = -2;
	printf("Testing isalnum...");
	while (++n < 256)
	{
		if (!!ft_isalnum(n) != !!isalnum(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}