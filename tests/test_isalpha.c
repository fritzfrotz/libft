#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	int	n = -2;
	printf("Testing isalnum...");
	while (++n < 256)
	{
		if (!!ft_isalpha(n) != !!isalpha(n))
		{
			printf("Error at %i", n);
			return (1);
		}
	}
	printf("success");
	return(0);
}