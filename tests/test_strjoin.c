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
    // Case 1: Both are NULL (e.g., s1 or s2 was NULL)
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

    // IMPORTANT: Free the memory allocated by ft_strjoin
    if (ft_result != NULL)
    {
        free(ft_result);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_strjoin(void)
{
    char    *s1;
    char    *s2;
    char    *result; // This will hold our new, joined string

    printf("\n--- Testing ft_strjoin ---\n");

    // --- Test 1: Basic joining ---
    s1 = "hello ";
    s2 = "world";
    result = ft_strjoin(s1, s2);
    check("Basic join", result, "hello world");

    // --- Test 2: s1 is empty ---
    s1 = "";
    s2 = "world";
    result = ft_strjoin(s1, s2);
    check("s1 is empty", result, "world");

    // --- Test 3: s2 is empty ---
    s1 = "hello";
    s2 = "";
    result = ft_strjoin(s1, s2);
    check("s2 is empty", result, "hello");

    // --- Test 4: Both are empty ---
    s1 = "";
    s2 = "";
    result = ft_strjoin(s1, s2);
    check("Both are empty", result, "");

    // --- Test 5: s1 is NULL (CRITICAL) ---
    s1 = NULL;
    s2 = "world";
    result = ft_strjoin(s1, s2);
    check("s1 is NULL", result, NULL);

    // --- Test 6: s2 is NULL (CRITICAL) ---
    s1 = "hello";
    s2 = NULL;
    result = ft_strjoin(s1, s2);
    check("s2 is NULL", result, NULL);

    // --- Test 7: Both are NULL ---
    s1 = NULL;
    s2 = NULL;
    result = ft_strjoin(s1, s2);
    check("Both are NULL", result, NULL);

    printf("---------------------------\n");
}