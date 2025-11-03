/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/

#include <string.h>
#include <stdio.h>
#include "libft.h"


typedef struct s_test_case
{
	char	*input;
	size_t		expected;
	char	*desciption;
}	t_test_case;


int	test_strlen(void)
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
	printf("testing ft_strlen...\n");
	while (test[i].input != NULL)
	{
		result = ft_strlen(test[i].input);
		if (result == strlen(test[i].input))
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