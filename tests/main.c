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
void test_strncmp(void);
void test_memcpy(void);
void test_memset(void);
void test_bzero(void);
void test_memchr(void);
void test_memcmp(void);
void test_calloc(void);
void test_strdup(void);
void test_substr(void);
void test_strjoin(void);










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
	test_strncmp();
	test_memcpy();
	test_memset();
	test_bzero();
	test_memchr();
	test_memcmp();
	test_calloc();
	test_strdup();
	test_substr();
	test_strjoin();





	printf("all tests completed");
}