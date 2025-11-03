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

int	test_tolower(void)
{
	int	n = -2;
	printf("Testing tolower...");
	while (++n < 256)
	{
		if (ft_tolower(n) != tolower(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success\n");
	return(0);
}