#include <stdio.h>
#include <string.h> // For memset and memcmp
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header


/*
* A static helper function so it doesn't conflict
* with 'check' in your other test files.
*/
static void check(const char *test_name, void *ft_dst, void *real_dst, size_t n)
{
    if (memcmp(ft_dst, real_dst, n) == 0)
        printf("  [PASS] %s\n", test_name);
    else
        printf("  [FAIL] %s\n", test_name);
}

/*
* This is the main test function that your main.c will call.
*/
void test_memcpy(void)
{
    char    src[] = "hello world";
    char    ft_dst[50];
    char    real_dst[50]; // Buffer for the real memcpy

    printf("\n--- Testing ft_memcpy ---\n");

    // --- Test 1: Basic full copy ---
    memset(ft_dst, 'A', 50);
    memset(real_dst, 'A', 50);
    ft_memcpy(ft_dst, src, 12); // 11 chars + '\0'
    memcpy(real_dst, src, 12); // Run the real one
    check("Basic copy (n=12)", ft_dst, real_dst, 12);

    // --- Test 2: The n=1 test (CRITICAL) ---
    memset(ft_dst, 'A', 50);
    memset(real_dst, 'A', 50);
    ft_memcpy(ft_dst, src, 1); // Copy just 'h'
    memcpy(real_dst, src, 1);
    check("n = 1 copy", ft_dst, real_dst, 5);

    // --- Test 3: The n=0 test (CRITICAL) ---
    memset(ft_dst, 'A', 50);
    memset(real_dst, 'A', 50);
    ft_memcpy(ft_dst, src, 0); // Copy nothing
    memcpy(real_dst, src, 0);
    check("n = 0 copy", ft_dst, real_dst, 5);
    
    printf("---------------------------\n");
}