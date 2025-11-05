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

    // IMPORTANT: Free the memory allocated by ft_strmapi
    if (ft_result != NULL)
    {
        free(ft_result);
    }
}

/*
* This is a simple 'mapper' function we will pass to ft_strmapi.
* It just adds 1 to each character.
*/
static char map_add_one(unsigned int i, char c)
{
    (void)i; // This silences the "unused parameter" warning
    return (c + 1);
}

/*
* This is another 'mapper' function that uses the index.
* It will only work for strings < 10 chars.
*/
static char map_use_index(unsigned int i, char c)
{
    (void)c; // We don't use 'c'
    return (i + '0'); // Convert index to a char
}

/*
* This is the main test function that your main.c will call.
*/
void test_strmapi(void)
{
    char    *s;
    char    *result;

    printf("\n--- Testing ft_strmapi ---\n");

    // --- Test 1: Basic map (c + 1) ---
    s = "hello";
    result = ft_strmapi(s, &map_add_one);
    check("Map 'hello' -> 'ifmmp'", result, "ifmmp");

    // --- Test 2: Map using index ---
    s = "abcde";
    result = ft_strmapi(s, &map_use_index);
    check("Map 'abcde' -> '01234'", result, "01234");
    
    // --- Test 3: Empty string ---
    s = "";
    result = ft_strmapi(s, &map_add_one);
    check("Map empty string", result, "");

    // --- Test 4: 's' is NULL (CRITICAL) ---
    result = ft_strmapi(NULL, &map_add_one);
    check("s is NULL", result, NULL);

    // --- Test 5: 'f' is NULL (CRITICAL) ---
    s = "hello";
    result = ft_strmapi(s, NULL);
    check("f is NULL", result, NULL);

    printf("---------------------------\n");
}