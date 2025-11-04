/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/

#include <stdio.h>
#include <string.h> // For the real strchr, to get expected results
#include "libft.h"

// A helper function to make the output clean
void static check(const char *test_name, char *result, char *expected)
{
    if (result == expected)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        // %p prints the memory address (the pointer)
        printf("  [FAIL] %s: Expected %p but got %p\n", test_name, expected, result);
    }
}

int test_strchr(void)
{
    char    str[] = "hello world";
    char    empty[] = "";
    char    *result;
    char    *expected;

    printf("--- Testing ft_strchr ---\n");

    // --- Test 1: Normal find in the middle ---
    // We want to find the first 'l'
    result = ft_strchr(str, 'l');
    expected = str + 2; // 'h' is str[0], 'e' is str[1], 'l' is str[2]
    check("Find 'l' in 'hello world'", result, expected);

    // --- Test 2: Find the first character ---
    result = ft_strchr(str, 'h');
    expected = str; // The very start of the string
    check("Find 'h' in 'hello world'", result, expected);

    // --- Test 3: Character not found ---
    // The function must return NULL
    result = ft_strchr(str, 'z');
    expected = NULL;
    check("Find 'z' (not found)", result, expected);

    // --- Test 4: The NUL-Terminator Test (CRITICAL) ---
    // The man page says the '\0' is part of the string.
    // The function MUST find the null terminator.
    result = ft_strchr(str, '\0');
    expected = str + 11; // The address of the end of "hello world"
    check("Find NUL-terminator '\\0'", result, expected);

    // --- Test 5: Test on empty string (not found) ---
    result = ft_strchr(empty, 'a');
    expected = NULL;
    check("Find 'a' in empty string", result, expected);

    // --- Test 6: NUL-Terminator on empty string (CRITICAL) ---
    // The function must find the null terminator
    result = ft_strchr(empty, '\0');
    expected = empty; // The address of the start (which is also the end)
    check("Find NUL-terminator in empty string", result, expected);

    printf("---------------------------\n");

    return (0);
}