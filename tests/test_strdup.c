#include <stdio.h>  // For printf
#include <string.h> // For strcmp
#include <stdlib.h> // For free
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
*/
void test_strdup(void)
{
    char    *s1;
    char    *s2; // This will hold our new, duplicated string

    printf("\n--- Testing ft_strdup ---\n");

    // --- Test 1: Basic string ---
    printf("  Testing 'hello world'...");
    s1 = "hello world";
    s2 = ft_strdup(s1);

    // Check 1: Did malloc fail?
    // Check 2: Is the content the same?
    // Check 3: Are the pointers different?
    if (s2 != NULL && strcmp(s1, s2) == 0 && s1 != s2)
    {
        printf(" [PASS]\n");
    }
    else
    {
        printf(" [FAIL] (Result was NULL, content mismatch, or pointers were the same)\n");
    }
    free(s2); // Must free the allocated memory

    // --- Test 2: Empty string (CRITICAL) ---
    printf("  Testing empty string \"\"...");
    s1 = "";
    s2 = ft_strdup(s1);

    if (s2 != NULL && strcmp(s1, s2) == 0 && s1 != s2)
    {
        printf(" [PASS]\n");
    }
    else
    {
        printf(" [FAIL] (Result was NULL, content mismatch, or pointers were the same)\n");
    }
    free(s2);

    // --- Test 3: NULL Input (Robustness check) ---
    // The real strdup segfaults, but a robust ft_strdup
    // might be protected (e.g., if your ft_strlen is).
    // If your test crashes here, it means your ft_strlen
    // (or your ft_strdup) isn't protected from NULL.
    
    // printf("  Testing NULL pointer...");
    // s1 = NULL;
    // s2 = ft_strdup(s1);
    // if (s2 == NULL)
    // {
    //     printf(" [PASS] (Correctly handled NULL)\n");
    // }
    // else
    // {
    //     printf(" [FAIL] (Did not return NULL for a NULL input)\n");
    // }
    // free(s2);

    printf("---------------------------\n");
}