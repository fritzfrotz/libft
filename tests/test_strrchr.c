/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

#include <stdio.h>  // For printf
#include <string.h> // For the real strrchr
#include "../libft.h" // To get your ft_strrchr

/*
* A helper function to make the test output clean.
* It compares the pointer from your function to the pointer from the real one.
*/
void static check(const char *test_name, char *ft_result, char *real_result)
{
    if (ft_result == real_result)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        // %p is the format specifier to print a pointer (memory address)
        printf("  [FAIL] %s: Expected %p but got %p\n", test_name, real_result, ft_result);
    }
}

/*
* This will be your test_strrchr() function.
* Make sure to add its prototype (void test_strrchr(void);)
* to your main.c and call it.
*/
void test_strrchr(void)
{
    char    str1[] = "hello lworld";
    char    str2[] = "hello world";
    char    str3[] = "hello";
    char    str4[] = "";
    char    str5[] = "xxxxx";
    char    *ft_result;
    char    *real_result;

    printf("\n--- Testing ft_strrchr ---\n");

    // Test 1: Find a char with multiple occurrences
    // (Should find the *last* 'l')
    ft_result = ft_strrchr(str1, 'l');
    real_result = strrchr(str1, 'l');
    check("Find 'l' in 'hello lworld'", ft_result, real_result);

    // Test 2: Find a char with one occurrence
    ft_result = ft_strrchr(str2, 'w');
    real_result = strrchr(str2, 'w');
    check("Find 'w' in 'hello world'", ft_result, real_result);

    // Test 3: Find the first char
    // (strrchr and strchr should be the same)
    ft_result = ft_strrchr(str2, 'h');
    real_result = strrchr(str2, 'h');
    check("Find 'h' in 'hello world'", ft_result, real_result);

    // Test 4: Char not found
    ft_result = ft_strrchr(str3, 'z');
    real_result = strrchr(str3, 'z'); // This will be NULL
    check("Find 'z' (not found) in 'hello'", ft_result, real_result);

    // Test 5: String of all the same char
    ft_result = ft_strrchr(str5, 'x');
    real_result = strrchr(str5, 'x'); // This should be str5 + 4
    check("Find 'x' in 'xxxxx'", ft_result, real_result);

    // --- CRITICAL EDGE CASES ---

    // Test 6: Find NUL-terminator ('\0')
    // The man page says this is allowed and should be found.
    ft_result = ft_strrchr(str3, '\0');
    real_result = strrchr(str3, '\0'); // This should be str3 + 5
    check("Find NUL-terminator in 'hello'", ft_result, real_result);

    // Test 7: Char not found in empty string
    ft_result = ft_strrchr(str4, 'a');
    real_result = strrchr(str4, 'a'); // This will be NULL
    check("Find 'a' in empty string", ft_result, real_result);

    // Test 8: Find NUL-terminator in empty string
    ft_result = ft_strrchr(str4, '\0');
    real_result = strrchr(str4, '\0'); // This should be str4 + 0
    check("Find NUL-terminator in empty string", ft_result, real_result);

    printf("---------------------------\n");
}