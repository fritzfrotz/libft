#include <stdio.h>  // For printf
#include <string.h> // For memset and memcmp
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* A static helper function so it doesn't conflict
* with 'check' in your other test files.
*
* It compares two blocks of memory.
*/
static void check(const char *test_name, const void *buf1, const void *buf2, size_t n)
{
    // memcmp returns 0 if the 'n' bytes of memory are identical
    if (memcmp(buf1, buf2, n) == 0)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        printf("  [FAIL] %s\n", test_name);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_memset(void)
{
    char    buffer1[50];
    char    buffer2[50];
    void    *return_ptr;

    printf("\n--- Testing ft_memset ---\n");

    // --- Test 1: Basic fill ---
    // Set first 10 bytes to 'A'
    ft_memset(buffer1, 'A', 10);
    // Create the expected result
    memset(buffer2, 'A', 10);
    check("Basic fill (n=10)", buffer1, buffer2, 10);

    // --- Test 2: Overwriting existing data ---
    // Set up a string, then overwrite the start
    strcpy(buffer1, "hello world");
    strcpy(buffer2, "hello world"); // Create the "expected" buffer
    
    ft_memset(buffer1, '*', 5); // Your function
    memset(buffer2, '*', 5); // The real function
    
    check("Overwrite 'hello' with '*'", buffer1, buffer2, 12); // Check whole string

    // --- Test 3: The n=0 test (CRITICAL) ---
    // (We'll re-use the buffers from Test 2)
    // buffer1 is now "***** world"
    ft_memset(buffer1, 'Z', 0); // Your function (should do nothing)
    memset(buffer2, 'Z', 0); // The real function (does nothing)
    
    check("n = 0 (do nothing)", buffer1, buffer2, 12);

    // --- Test 4: The return value test (CRITICAL) ---
    printf("  Testing return value...");
    return_ptr = ft_memset(buffer1, 'B', 1);
    
    if (return_ptr == (void *)buffer1)
    {
        printf(" [PASS]\n");
    }
    else
    {
        printf(" [FAIL]: Expected %p, got %p\n", (void *)buffer1, return_ptr);
    }

    printf("---------------------------\n");
}