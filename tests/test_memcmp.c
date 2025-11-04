#include <stdio.h>
#include <string.h> // For the real memcmp
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking the sign.
* It won't conflict with other 'check' functions.
*/
static void check_sign(const char *test_name, int ft_result, int real_result)
{
    // Get the "sign" of the result (-1, 0, or 1)
    int ft_sign = (ft_result > 0) ? 1 : (ft_result < 0) ? -1 : 0;
    int real_sign = (real_result > 0) ? 1 : (real_result < 0) ? -1 : 0;

    if (ft_sign == real_sign)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        printf("  [FAIL] %s: Expected sign %d, got sign %d\n", 
            test_name, real_sign, ft_sign);
    }
}

/*
* This is the main test function that your main.c will call.
*/
void test_memcmp(void)
{
    char    s1[] = "hello\0world";
    char    s2[] = "hello\0apple";
    char    s3[] = "hello";
    char    s4[] = "hellob";
    int     ft_res;
    int     real_res;

    printf("\n--- Testing ft_memcmp ---\n");

    // --- Test 1: Identical strings ---
    ft_res = ft_memcmp(s3, "hello", 6); // n=6 to include the '\0'
    real_res = memcmp(s3, "hello", 6);
    check_sign("Identical", ft_res, real_res);

    // --- Test 2: 'n' stops before difference ---
    ft_res = ft_memcmp(s3, s4, 5); // Compares "hello" and "hellob" up to n=5
    real_res = memcmp(s3, s4, 5);
    check_sign("n stops before diff", ft_res, real_res);

    // --- Test 3: 'n=0' (CRITICAL) ---
    ft_res = ft_memcmp(s3, "world", 0);
    real_res = memcmp(s3, "world", 0);
    check_sign("n = 0", ft_res, real_res);

    // --- Test 4: Compares *after* NUL (CRITICAL) ---
    // This is the big test. strncmp would stop at '\0'.
    // We compare "hello\0world" and "hello\0apple" for 12 bytes.
    // The difference is at 'w' vs 'a'.
    ft_res = ft_memcmp(s1, s2, 12);
    real_res = memcmp(s1, s2, 12);
    check_sign("Compares after NUL (s1 > s2)", ft_res, real_res);

    // --- Test 5: Unsigned char test ---
    // (unsigned char)200 > (unsigned char)100
    ft_res = ft_memcmp("\200", "\100", 1);
    real_res = memcmp("\200", "\100", 1);
    check_sign("Unsigned char diff (200 > 100)", ft_res, real_res);

    printf("---------------------------\n");
}