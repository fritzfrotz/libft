#include <stdio.h>  // For printf
#include <string.h> // For strcmp
#include <stdlib.h> // For free, NULL
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking.
* It's different from the others because it must free the
* 'ft_result' pointer after checking it.
*/
static void check(const char *test_name, char *ft_result, const char *expected)
{
    // Case 1: Both are NULL (e.g., s was NULL)
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

    // IMPORTANT: Free the memory allocated by ft_substr
    if (ft_result != NULL)
    {
        free(ft_result);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_substr(void)
{
    char    *s = "hello world";
    char    *result;

    printf("\n--- Testing ft_substr ---\n");

    // --- Test 1: Normal middle substring ---
    result = ft_substr(s, 6, 5); // "world"
    check("Normal 'world'", result, "world");

    // --- Test 2: Substring from start ---
    result = ft_substr(s, 0, 5); // "hello"
    check("From start 'hello'", result, "hello");

    // --- Test 3: 'len' is too long (CRITICAL) ---
    // Should stop at the '\0'
    result = ft_substr(s, 6, 20); // "world"
    check("'len' is too long", result, "world");

    // --- Test 4: 'start' is past the end (CRITICAL) ---
    // Should return an empty, allocated string
    result = ft_substr(s, 20, 5); // ""
    check("'start' is past end", result, "");

    // --- Test 5: 'len = 0' (CRITICAL) ---
    // Should return an empty, allocated string
    result = ft_substr(s, 6, 0); // ""
    check("'len' is 0", result, "");

    // --- Test 6: Source string 's' is NULL ---
    result = ft_substr(NULL, 0