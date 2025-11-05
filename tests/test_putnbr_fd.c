#include <stdio.h>  // For printf
#include <unistd.h> // For write
#include <limits.h> // For INT_MAX and INT_MIN
#include "../libft.h" // Include your main header

/*
* This is the main test function that your main.c will call.
* It is a visual test.
*/
void test_putnbr_fd(void)
{
    printf("\n--- Testing ft_putnbr_fd ---\n");
    
    // --- Test 1: Basic positive ---
    printf("  Test 1: You should see '123' on the next line:\n  ");
    ft_putnbr_fd(123, 1);
    ft_putchar_fd('\n', 1);

    // --- Test 2: Basic negative ---
    printf("  Test 2: You should see '-456' on the next line:\n  ");
    ft_putnbr_fd(-456, 1);
    ft_putchar_fd('\n', 1);

    // --- Test 3: Zero (CRITICAL) ---
    printf("  Test 3: You should see '0' on the next line:\n  ");
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);

    // --- Test 4: INT_MAX (CRITICAL) ---
    printf("  Test 4: You should see '2147483647' on the next line:\n  ");
    ft_putnbr_fd(INT_MAX, 1); // 2147483647
    ft_putchar_fd('\n', 1);
    
    // --- Test 5: INT_MIN (MOST CRITICAL) ---
    printf("  Test 5: You should see '-2147483648' on the next line:\n  ");
    ft_putnbr_fd(INT_MIN, 1); // -2147483648
    ft_putchar_fd('\n', 1);

    // --- Test 6: Standard Error (fd = 2) ---
    printf("  Test 6: You should see '987' (on stderr) on the next line:\n  ");
    ft_putnbr_fd(987, 2);
    ft_putchar_fd('\n', 2);

    printf("---------------------------\n");
}