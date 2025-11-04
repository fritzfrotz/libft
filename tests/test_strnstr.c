/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

#include <stdio.h>
#include <string.h> // For strncmp and real strnstr if you have it
#include "../libft.h"

/*
* A static helper function to make test output clean.
* It compares the pointer from your function to the expected pointer.
*/
static void check(const char *test_name, char *ft_result, char *expected)
{
    if (ft_result == expected)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        // %p is the format specifier to print a pointer (memory address)
        printf("  [FAIL] %s: Expected %p but got %p\n", test_name, expected, ft_result);
    }
}

/*
* This will be your test_strnstr() function.
* Add its prototype (void test_strnstr(void);) to your main.c
* and call it from there.
*/
void test_strnstr(void)
{
    char    haystack[] = "lorem ipsum dolor sit amet";
    char    *empty = "";
    char    *ft_result;
    char    *expected;

    printf("\n--- Testing ft_strnstr ---\n");

    // --- Test 1: Normal find (within len) ---
    // Find "ipsum" (starts at index 6) with len=10
    ft_result = ft_strnstr(haystack, "ipsum", 11);
    expected = haystack + 6;
    check("Find 'ipsum' with len=11", ft_result, expected);

    // --- Test 2: Find at start ---
    ft_result = ft_strnstr(haystack, "lorem", 10);
    expected = haystack;
    check("Find 'lorem' at start", ft_result, expected);

    // --- Test 3: Not found ---
    ft_result = ft_strnstr(haystack, "z", 20);
    expected = NULL;
    check("Find 'z' (not found)", ft_result, expected);

    // --- Test 4: Found, but START is AFTER len (CRITICAL) ---
    // Find "dolor" (starts at 12) but with len=10
    ft_result = ft_strnstr(haystack, "dolor", 10);
    expected = NULL;
    check("Find 'dolor' with len=10 (fail)", ft_result, expected);

    // --- Test 5: Empty needle (CRITICAL) ---
    // Must always return haystack
    ft_result = ft_strnstr(haystack, "", 10);
    expected = haystack;
    check("Find empty needle '' with len=10", ft_result, expected);

    // --- Test 6: Empty needle with len=0 (CRITICAL) ---
    // Must still return haystack
    ft_result = ft_strnstr(haystack, "", 0);
    expected = haystack;
    check("Find empty needle '' with len=0", ft_result, expected);

    // --- Test 7: Empty haystack ---
    ft_result = ft_strnstr(empty, "hello", 5);
    expected = NULL;
    check("Find 'hello' in empty haystack", ft_result, expected);

    // --- Test 8: Empty haystack AND empty needle ---
    ft_result = ft_strnstr(empty, "", 5);
    expected = empty;
    check("Find empty needle in empty haystack", ft_result, expected);

    // --- Test 9: Needle longer than haystack ---
    ft_result = ft_strnstr("hello", "helloworld", 10);
    expected = NULL;
    check("Needle longer than haystack", ft_result, expected);
    
    printf("---------------------------\n");
}