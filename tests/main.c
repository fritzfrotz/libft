#include <stdio.h>

int	test_atoi(void);
int	test_isalnum(void);
int	test_isalpha(void);
int	test_isdigit(void);
int	test_isprint(void);
int	test_isascii(void);
int	test_tolower(void);
int	test_toupper(void);
int	test_strlen(void);
int	test_strlcpy(void);
int test_strlcat(void);
int test_strchr(void);
void test_strrchr(void);
void test_strnstr(void);






int	main(void)
{
	test_atoi();
	test_isalnum();
	test_isalpha();
	test_isdigit();
	test_isprint();
	test_isascii();
	test_tolower();
	test_toupper();
	test_strlen();
	test_strlcpy();
	test_strlcat();
	test_strchr();
	test_strrchr();
	test_strnstr();



	printf("all tests completed");
}