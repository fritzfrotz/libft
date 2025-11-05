#include <stdio.h>  // For printf
#include <string.h> // For strcmp
#include <stdlib.h> // For free, NULL
#include <limits.h> // For INT_MAX and INT_MIN
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking.
* It frees the 'ft_result' pointer after checking it.
*/
static void check(const char *test_name, char *ft_result, const char *expected)
{
    // Case 1: Both are NULL (e.g., malloc failed)
    if (ft_result == NULL && expected == NULL)
    {
        printf("  [PASS] %s\n", test_name);
    }
    // Case 2: One is NULL, but not the other (FAIL)
    else if (ft_result == NULL || expected == NULL)
    {
        printf("  [FAIL] %s: Expected %s, got %s\n", test_name, 
            expected ? expected : "NULL", 
            ft_result ? ft_result : "NULL");
    }
    // Case 3: Both are non-NULL, so we check their content
    else if (strcmp(ft_result, expected) == 0)
    {
        printf("  [PASS] %s\n", test_name);
    }
    // Case 4: Content mismatch (FAIL)
    else
    {
        printf("  [FAIL] %s: Expected '%s', got '%s'\n", 
            test_name, expected, ft_result);
    }

    // IMPORTANT: Free the memory allocated by ft_itoa
    if (ft_result != NULL)
    {
        free(ft_result);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_itoa(void)
{
    char    *result;

    printf("\n--- Testing ft_itoa ---\n");

    // --- Test 1: Basic positive ---
    result = ft_itoa(123);
    check("Basic positive", result, "123");

    // --- Test 2: Basic negative ---
    result = ft_itoa(-456);
    check("Basic negative", result, "-456");

    // --- Test 3: Zero (CRITICAL) ---
    result = ft_itoa(0);
    check("Zero", result, "0");

    // --- Test 4: INT_MAX (CRITICAL) ---
    result = ft_itoa(2147483647);
    check("INT_MAX", result, "2147483647");

    // --- Test 5: INT_MIN (MOST CRITICAL) ---
    result = ft_itoa(-2147483648);
    check("INT_MIN", result, "-2147483648");

    // --- Test 6: Another simple number ---
    result = ft_itoa(1);
    check("Single digit", result, "1");
    
    // --- Test 7: Another simple negative ---
    result = ft_itoa(-1);
    check("Single negative", result, "-1");

    printf("---------------------------\n");
}