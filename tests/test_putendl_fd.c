#include <stdio.h>  // For printf
#include <unistd.h> // For write
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
* It is a visual test.
*/
void test_putendl_fd(void)
{
    printf("\n--- Testing ft_putendl_fd ---\n");
    
    // --- Test 1: Write to fd = 1 (Standard Output) ---
    printf("  Test 1 (stdout): You should see 'Line 1' and 'Line 2' on separate lines below:\n");
    ft_putendl_fd("Line 1", 1);
    ft_putendl_fd("Line 2", 1);

    // --- Test 2: Write to fd = 2 (Standard Error) ---
    printf("  Test 2 (stderr): You should see 'Error 1' and 'Error 2' on separate lines below:\n");
    ft_putendl_fd("Error 1", 2);
    ft_putendl_fd("Error 2", 2);

    // --- Test 3: Empty string (CRITICAL) ---
    printf("  Test 3 (Empty string): You should see a blank line between the '[]':\n[");
    ft_putendl_fd("", 1);
    printf("]\n");

    // --- Test 4: NULL string (CRITICAL) ---
    // This just checks that your function doesn't segfault.
    printf("  Test 4 (NULL string): You should see nothing (and no crash):\n");
    ft_putendl_fd(NULL, 1);
    printf("  (No crash)\n");

    printf("---------------------------\n");
}