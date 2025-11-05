#include <stdio.h>  // For printf
#include <unistd.h> // For write (which ft_putchar_fd uses)
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
* It does not have a 'check' function because the output
* is to the terminal.
*/
void test_putchar_fd(void)
{
    printf("\n--- Testing ft_putchar_fd ---\n");
    
    // --- Test 1: Write to fd = 1 (Standard Output) ---
    printf("  Test 1: You should see 'a b c' on the next line:\n  ");
    
    // Call your function multiple times
    ft_putchar_fd('a', 1);
    ft_putchar_fd(' ', 1);
    ft_putchar_fd('b', 1);
    ft_putchar_fd(' ', 1);
    ft_putchar_fd('c', 1);
    ft_putchar_fd('\n', 1); // Add a newline at the end

    // --- Test 2: Write to fd = 2 (Standard Error) ---
    // This will also print to your terminal, but it proves
    // the 'fd' parameter is being used.
    printf("  Test 2: You should see 'ERROR' on the next line:\n  ");
    ft_putchar_fd('E', 2);
    ft_putchar_fd('R', 2);
    ft_putchar_fd('R', 2);
    ft_putchar_fd('O', 2);
    ft_putchar_fd('R', 2);
    ft_putchar_fd('\n', 2);
    
    printf("---------------------------\n");
}