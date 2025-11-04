/*
todo:
[x] header
[x] maker
[x] maker_test
[ ] testing
*/

#include <stdio.h>
#include <string.h> // For the real strncmp
#include "../libft.h"

/*
* This is a static helper function, so it won't conflict
* with 'check' functions in your other test files.
*
* It's special for strncmp: it checks if the *sign*
* of your function's result matches the *sign* of the
* real function's result.
*/
static void check(const char *test_name, const char *s1, const char *s2, size_t n)
{
    int ft_result = ft_strncmp(s1, s2, n);
    int real_result = strncmp(s1, s2, n);

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
* This will be your test_strncmp() function.
* Add its prototype (void test_strncmp(void);) to your main.c
* and call it from there.
*/
void test_strncmp(void)
{
    printf("\n--- Testing ft_strncmp ---\n");

    // Test 1: Identical strings
    check("Identical", "hello", "hello", 5);

    // Test 2: Different strings (s1 < s2)
    check("s1 < s2", "helloa", "hellob", 6);

    // Test 3: Different strings (s1 > s2)
    check("s1 > s2", "hellob", "helloa", 6);

    // Test 4: 'n' stops before the difference (CRITICAL)
    check("n stops before diff", "hellob", "helloa", 5);

    // Test 5: 'n = 0' (CRITICAL)
    check("n = 0", "hello", "world", 0);

    // Test 6: One string is shorter (s1 < s2)
    // Compares '\0' from s1 to 'o' from s2
    check("s1 shorter", "hello", "helloo", 6);

    // Test 7: One string is shorter (s1 > s2)
    // Compares 'o' from s1 to '\0' from s2
    check("s2 shorter", "helloo", "hello", 6);

    // Test 8: Identical up to 'n'
    check("Identical up to n", "abc", "abcde", 3);

    // Test 9: Different with unsigned chars
    // (char)200 is negative, (char)100 is positive
    check("Unsigned char diff", "\200", "\100", 1);
    
    printf("---------------------------\n");
}