#include <stdio.h>  // For printf
#include <string.h> // For the real memmove, memset, and memcmp
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking.
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
void test_memmove(void)
{
    char    ft_buf[100];
    char    real_buf[100];

    printf("\n--- Testing ft_memmove ---\n");

    // --- Test 1: No overlap (should act like memcpy) ---
    memset(ft_buf, 'A', 100);
    memset(real_buf, 'A', 100);
    strcpy(ft_buf, "hello");
    strcpy(real_buf, "hello");
    
    ft_memmove(ft_buf + 5, " world", 6); // Add " world" + '\0'
    memmove(real_buf + 5, " world", 6);
    check("No overlap", ft_buf, real_buf, 12);

    // --- Test 2: Overlap: dest > src (CRITICAL) ---
    // (e.g., "hello world" -> "hello hello")
    strcpy(ft_buf, "hello world");
    strcpy(real_buf, "hello world");

    // Move "hello" (src=ft_buf) onto "world" (dest=ft_buf+6)
    ft_memmove(ft_buf + 6, ft_buf, 5);
    memmove(real_buf + 6, real_buf, 5);
    check("Overlap: dest > src", ft_buf, real_buf, 15);

    // --- Test 3: Overlap: dest < src (CRITICAL) ---
    // (e.g., "hello world" -> "world world")
    strcpy(ft_buf, "hello world");
    strcpy(real_buf, "hello world");

    // Move "world" (src=ft_buf+6) onto "hello" (dest=ft_buf)
    ft_memmove(ft_buf, ft_buf + 6, 5);
    memmove(real_buf, real_buf + 6, 5);
    check("Overlap: dest < src", ft_buf, real_buf, 15);

    // --- Test 4: The n=0 test (CRITICAL) ---
    // (We'll re-use the buffers from Test 3)
    ft_memmove(ft_buf, ft_buf + 1, 0); // Should do nothing
    memmove(real_buf, real_buf + 1, 0); // Should do nothing
    check("n = 0 (do nothing)", ft_buf, real_buf, 15);

    printf("---------------------------\n");
}