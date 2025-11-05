#include <stdio.h>  // For printf
#include <stdlib.h> // For size_t and free
#include <limits.h> // For SIZE_MAX
#include "../libft.h" // Include your main header

/*
* This static helper function checks if 'n' bytes of a
* memory block 'mem' are all zero.
* Returns 1 (true) if all zeros, 0 (false) otherwise.
*/
static int is_all_zeros(const void *mem, size_t n)
{
    const unsigned char *p = (const unsigned char *)mem;
    size_t i = 0;

    while (i < n)
    {
        if (p[i] != 0)
        {
            return (0); // Found a non-zero byte
        }
        i++;
    }
    return (1); // All bytes were zero
}

/*
* This is the main test function that your main.c will call.
*/
void test_calloc(void)
{
    void    *mem;
    
    printf("\n--- Testing ft_calloc ---\n");

    // --- Test 1: Basic allocation ---
    printf("  Testing basic allocation (10, 4)...");
    mem = ft_calloc(10, 4);
    if (mem != NULL && is_all_zeros(mem, 40))
    {
        printf(" [PASS]\n");
    }
    else
    {
        printf(" [FAIL] (mem was NULL or not zeroed)\n");
    }
    free(mem); // Always free the memory

    // --- Test 2: The "Size 0" test (CRITICAL) ---
    // Subject says this must return a valid, free-able pointer
    printf("  Testing size = 0 (0, 10)...");
    mem = ft_calloc(0, 10);
    if (mem != NULL)
    {
        printf(" [PASS]\n");
    }
    else
    {
        printf(" [FAIL] (mem was NULL)\n");
    }
    free(mem); // Must be free-able

    // --- Test 3: The "nmemb = 0" test (CRITICAL) ---
    printf("  Testing nmemb = 0 (10, 0)...");
    mem = ft_calloc(10, 0);
    if (mem != NULL)
    {
        printf(" [PASS]\n");
	}
}