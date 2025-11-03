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

int	test_toupper(void)
{
	int	n = -2;
	printf("Testing toupper...");
	while (++n < 256)
	{
		if (ft_toupper(n) != toupper(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}