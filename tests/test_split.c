#include <stdio.h>  // For printf
#include <string.h> // For strcmp
#include <stdlib.h> // For free, NULL
#include "../libft.h" // Include your main header

/*
* This is a static helper function to free all the memory
* allocated by ft_split.
*/
static void free_split_array(char **array)
{
    int i = 0;

    if (!array)
        return;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

/*
* This is a static helper function for checking the result.
* It's complex because we have to compare two arrays of strings.
*/
static void check(const char *test_name, char **ft_result, char **expected)
{
    int i = 0;
    int pass = 1; // Start by assuming it passed

    // Case 1: Check for NULL (e.g., s was NULL or malloc failed)
    if (ft_result == NULL && expected == NULL)
    {
        printf("  [PASS] %s (Got NULL as expected)\n", test_name);
        return; // Test is over
    }
    
    // Case 2: One is NULL, but not the other (FAIL)
    if (ft_result == NULL || expected == NULL)
    {
        printf("  [FAIL] %s: Expected %p, got %p\n", test_name,
            (void *)expected, (void *)ft_result);
        free_split_array(ft_result);
        return;
    }

    // Case 3: Compare content string by string
    while (expected[i] != NULL && ft_result[i] != NULL)
    {
        if (strcmp(ft_result[i], expected[i]) != 0)
        {
            pass = 0; // Content mismatch
            break;
        }
        i++;
    }

    // After the loop, check if they *both* ended at the same time
    if (pass && ft_result[i] == NULL && expected[i] == NULL)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        printf("  [FAIL] %s: Content or length mismatch.\n", test_name);
        // You can add more printf's here to show the exact error
    }

    // IMPORTANT: Free the memory allocated by ft_split
    free_split_array(ft_result);
}

/*
* This is the main test function that your main.c will call.
*/
void test_split(void)
{
    char    **result;

    printf("\n--- Testing ft_split ---\n");

    // --- Test 1: Basic split ---
    result = ft_split("hello world", ' ');
    check("Basic split", result, (char *[]){"hello", "world", NULL});

    // --- Test 2: Multiple delimiters ---
    result = ft_split("hello   world foo", ' ');
    check("Multiple delims", result, (char *[]){"hello", "world", "foo", NULL});

    // --- Test 3: Leading/Trailing delimiters (CRITICAL) ---
    result = ft_split("  hello world  ", ' ');
    check("Leading/Trailing delims", result, (char *[]){"hello", "world", NULL});

    // --- Test 4: Only delimiters ---
    result = ft_split("     ", ' ');
    check("Only delims", result, (char *[]){NULL});

    // --- Test 5: Empty string ---
    result = ft_split("", ' ');
    check("Empty string", result, (char *[]){NULL});

    // --- Test 6: No delimiters ---
    result = ft_split("helloworld", ' ');
    check("No delims", result, (char *[]){"helloworld", NULL});

    // --- Test 7: String is NULL (CRITICAL) ---
    result = ft_split(NULL, ' ');
    check("s is NULL", result, NULL);

    printf("---------------------------\n");
}