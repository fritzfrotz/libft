#include <stdio.h>
#include "libft.h"

typedef struct s_test_case
{
	char	*input;
	int		expected;
	char	*desciption;
}	t_test_case;


int	main(void)
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
	while (test[i].input != NULL)
	{
		result = ft_atoi(test[i].input);
		if (result == atoi(test[i].expected))
			printf("%n" , test[i].desciption);
		else
		{
			printf("fail at %n, got %i, expeected %i", test[i].desciption, result, test[i].expected);
		return (1);
		}
		++i;
	}
	return (0);
}