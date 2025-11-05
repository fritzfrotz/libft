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
void test_strtrim(void);
void test_split(void);
void test_itoa(void);
void test_strmapi(void);
void test_striteri(void);
void test_putchar_fd(void);
void test_putstr_fd(void);
void test_putendl_fd(void);
void test_putnbr_fd(void);
void test_memmove(void);













int	main(void)
{
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
	test_strdup();
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	
	test_memcpy();
	test_memset();
	test_bzero();
	test_memchr();
	test_memcmp();
	test_calloc();
	test_memmove();

	test_itoa();
	test_atoi();

	test_strmapi();
	test_striteri();

	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();











	printf("all tests completed");
}