#include <stdio.h>  // For printf
#include <string.h> // For the real memchr
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* This is a static helper function, so it won't conflict
* with 'check' in your other test files.
*
* It compares the pointer from your function to the pointer from the real one.
*/
static void check(const char *test_name, void *ft_result, void *real_result)
{
    if (ft_result == real_result)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        // %p is the format specifier to print a pointer (memory address)
        printf("  [FAIL] %s: Expected %p but got %p\n", test_name, real_result, ft_result);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_memchr(void)
{
    char    str[] = "hello\0world"; // A string with an embedded NULL

    void    *ft_result;
    void    *real_result;

    printf("\n--- Testing ft_memchr ---\n");

    // --- Test 1: Find a char in a string ---
    // Find 'l' within the first 5 bytes
    ft_result = ft_memchr(str, 'l', 5);
    real_result = memchr(str, 'l', 5); // Expected: str + 2
    check("Find 'l' in 'hello'", ft_result, real_result);

    // --- Test 2: Char not found (within n) ---
    // 'w' is in the string, but *after* the n limit
    ft_result = ft_memchr(str, 'w', 5);
    real_result = memchr(str, 'w', 5); // Expected: NULL
    check("Find 'w' with n=5 (fail)", ft_result, real_result);

    // --- Test 3: Find the embedded NUL (CRITICAL) ---
    // This is the big difference from strchr
    ft_result = ft_memchr(str, '\0', 12);
    real_result = memchr(str, '\0', 12); // Expected: str + 5
    check("Find '\\0' in 'hello\\0world'", ft_result, real_result);

    // --- Test 4: The n=0 test (CRITICAL) ---
    // Should search 0 bytes and find nothing
    ft_result = ft_memchr(str, 'h', 0);
    real_result = memchr(str, 'h', 0); // Expected: NULL
    check("Find 'h' with n=0", ft_result, real_result);

    // --- Test 5: Find data in an int array ---
    // We search for the byte pattern of the int 30.
    // An int is 4 bytes, so we search for its first byte.
    // This is a bit advanced, but shows it works on non-char memory.
    // Note: This test (finding '30') is a bit weak, but
    // finding the byte value is more complex.
    // Let's test finding the *character* 'l' in "hello" again.
    
    // --- Test 5 (Simpler): Find last char within n ---
    ft_result = ft_memchr(str, 'o', 5);
    real_result = memchr(str, 'o', 5); // Expected: str + 4
    check("Find 'o' (last char) in 'hello'", ft_result, real_result);


    printf("---------------------------\n");
}