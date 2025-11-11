#include <stdio.h>  // For printf (only for the main header)
#include <unistd.h> // For write
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
* It is a visual test.
*/
void test_putendl_fd(void)
{
    // Use ft_putstr_fd to print, to avoid mixing with printf
    ft_putstr_fd("\n--- Testing ft_putendl_fd ---\n", 1);
    
    // --- Test 1: Write to fd = 1 (Standard Output) ---
    ft_putstr_fd("  Test 1 (stdout): You should see 'Line 1' and 'Line 2' on separate lines below:\n", 1);
    ft_putendl_fd("Line 1", 1);
    ft_putendl_fd("Line 2", 1);

    // --- Test 2: Write to fd = 2 (Standard Error) ---
    ft_putstr_fd("  Test 2 (stderr): You should see 'Error 1' and 'Error 2' on separate lines below:\n", 1);
    ft_putendl_fd("Error 1", 2);
    ft_putendl_fd("Error 2", 2);

    // --- Test 3: Empty string (CRITICAL) ---
    // This is the fixed test.
    ft_putstr_fd("  Test 3 (Empty string): You should see a blank line between the '[]':\n", 1);
    ft_putstr_fd("[", 1);
    ft_putendl_fd("", 1); // This will print '\n'
    ft_putstr_fd("]\n", 1);

    // --- Test 4: NULL string (CRITICAL) ---
    ft_putstr_fd("  Test 4 (NULL string): You should see nothing (and no crash):\n", 1);
    ft_putendl_fd(NULL, 1);
    ft_putstr_fd("  (No crash)\n", 1);

    ft_putstr_fd("---------------------------\n", 1);
}