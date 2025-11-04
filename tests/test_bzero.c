#include <stdio.h>  // For printf
#include <string.h> // For memset and memcmp
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* This is a static helper function so it doesn't conflict
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
void test_bzero(void)
{
    char    buffer1[50]; // For your ft_bzero
    char    buffer2[50]; // For the "expected" result
    
    printf("\n--- Testing ft_bzero ---\n");

    // --- Test 1: Basic zeroing ---
    // First, fill both buffers with 'A's
    memset(buffer1, 'A', 50);
    memset(buffer2, 'A', 50);

    // Zero out the first 10 bytes in both
    ft_bzero(buffer1, 10);
    memset(buffer2, '\0', 10); // The "expected" result
    
    check("Basic zeroing (n=10)", buffer1, buffer2, 50);

    // --- Test 2: Overwriting existing data ---
    // Set up a string, then zero the start
    strcpy(buffer1, "hello world");
    strcpy(buffer2, "hello world");
    
    ft_bzero(buffer1, 5); // Your function
    memset(buffer2, '\0', 5); // The real function
    
    // The first 5 bytes should be '\0', the rest " world"
    check("Overwrite 'hello' with '\\0'", buffer1, buffer2, 12);

    // --- Test 3: The n=0 test (CRITICAL) ---