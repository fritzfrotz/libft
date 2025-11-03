/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/


#include <stdio.h>
#include <stdlib.h>
#include "libft.h"


typedef struct s_test_case
{
	char	*input;
	int		expected;
	char	*desciption;
}	t_test_case;


int	test_atoi(void)
{
	t_test_case test[] = {
		{"42", 42, "Basic Positive"},
		{"-42", -42, "Basic Negative"},
		{"  567", 567, "Leading Whitespaces"},
		{"    -567", -567, "Leading Whitespaces Negative"},
		{"2147483647", 2147483647, "Max int"},
		{"-2147483647", -2147483647, "Negative Max Int"},
		{"534huy", 534, "Stop at Letter"},
		{NULL, 0, NULL}
	};
	int i = 0;
	int result;
	printf("testing ft_atoi...\n");
	while (test[i].input != NULL)
	{
		result = ft_atoi(test[i].input);
		if (result == atoi(test[i].input))
			printf("%s, " , test[i].desciption);
		else
		{
			printf("fail at %s, got %i, expeected %i", test[i].desciption, result, test[i].expected);
		return (1);
		}
		++i;
	}
	printf("\ntests completed\n");
	return (0);
}