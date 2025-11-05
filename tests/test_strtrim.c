#include <stdio.h>  // For printf
#include <string.h> // For strcmp
#include <stdlib.h> // For free, NULL
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking.
* It frees the 'ft_result' pointer after checking it.
*/
static void check(const char *test_name, char *ft_result, const char *expected)
{
    // Case 1: Both are NULL
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

    // IMPORTANT: Free the memory allocated by ft_strtrim
    if (ft_result != NULL)
    {
        free(ft_result);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_strtrim(void)
{
    char    *s1;
    char    *set;
    char    *result;

    printf("\n--- Testing ft_strtrim ---\n");

    // --- Test 1: Basic trim ---
    s1 = "xxhelloxx";
    set = "x";
    result = ft_strtrim(s1, set);
    check("Basic trim 'x'", result, "hello");

    // --- Test 2: Complex set ---
    s1 = "xy yxhello worldy x y";
    set = "xy ";
    result = ft_strtrim(s1, set);
    check("Complex set 'xy '", result, "hello world");

    // --- Test 3: No trim needed ---
    s1 = "hello world";
    set = "xy";
    result = ft_strtrim(s1, set);
    check("No trim needed", result, "hello world");

    // --- Test 4: All chars are in set (CRITICAL) ---
    s1 = "xxxxxxxxx";
    set = "x";
    result = ft_strtrim(s1, set);
    check("All chars trimmed", result, "");

    // --- Test 5: String is empty ---
    s1 = "";
    set = "x";
    result = ft_strtrim(s1, set);
    check("String is empty", result, "");

    // --- Test 6: Set is empty ---
    s1 = "xxhelloxx";
    set = "";
    result = ft_strtrim(s1, set);
    check("Set is empty", result, "xxhelloxx");

    // --- Test 7: s1 is NULL (CRITICAL) ---
    s1 = NULL;
    set = "x";
    result = ft_strtrim(s1, set);
    check("s1 is NULL", result, NULL);

    // --- Test 8: set is NULL (CRITICAL) ---
    s1 = "hello";
    set = NULL;
    result = ft_strtrim(s1, set);
    // A robust function should handle this. Returning a copy is safest.
    // If your strchr-helper segfaults, this will fail.
    check("set is NULL", result, "hello"); 

    printf("---------------------------\n");
}