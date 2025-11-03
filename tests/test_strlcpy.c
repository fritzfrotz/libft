#include "../libft.h"
#include <stdio.h>
#include <ctype.h>

/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

int	main(void)
{
	int	i;

	//copy strings
	//edge cases?


	printf("Testing ft_isprint...\n");
	i = -1;
	while ((i<= 255) && (ft_strlcpy(i) == strlcpy(i)))
	{
		++i;
	}
	if (i == 256)
		printf("all tests completed!\n");
	else
		printf("error at %d\n, ft func = %d, real func = %d", i, ft_isprint(i), isprint(i));
		return (1);
	return (0);
}