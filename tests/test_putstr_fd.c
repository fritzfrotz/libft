#include <stdio.h>  // For printf
#include <unistd.h> // For write (which ft_putstr_fd uses)
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
* It does not have a 'check' function because the output
* is to the terminal.
*/
void test_putstr_fd(void)
{
    printf("\n--- Testing ft_putstr_fd ---\n");
    
    // --- Test 1: Write to fd = 1 (Standard Output) ---
    printf("  Test 1 (stdout): You should see 'Hello World' on the next line:\n  ");
    ft_putstr_fd("Hello World", 1);
    ft_putstr_fd("\n", 1); // Add a newline

    // --- Test 2: Write to fd = 2 (Standard Error) ---
    // This also prints to the terminal, but proves 'fd' is used.
    printf("  Test 2 (stderr): You should see 'This is an error' on the next line:\n  ");
    ft_putstr_fd("This is an error", 2);
    ft_putstr_fd("\n", 2);

    // --- Test 3: Empty string (CRITICAL) ---
    printf("  Test 3 (Empty string): You should see nothing between the '[]':\n  [");
    ft_putstr_fd("", 1);
    printf("]\n");

    // --- Test 4: NULL string (CRITICAL) ---
    // This just checks that your function doesn't segfault.
    printf("  Test 4 (NULL string): You should see nothing (and no crash):\n  [");
    ft_putstr_fd(NULL, 1);
    printf("] (No crash)\n");

    printf("---------------------------\n");
}