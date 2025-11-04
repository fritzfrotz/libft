/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/

#include <stdio.h>
#include <string.h> // For memset and the real strlcpy (to compare)
#include "libft.h"

int test_strlcpy(void)
{
    // --- Test 1: A normal, full copy ---
    printf("testing strlcpy\n--- test 1: Normal Copy ---\n");
    char    src1[] = "hello";
    char    dst1[10];
    size_t  ret1;

    // Fill dst with 'A's to see the NUL-terminator
    memset(dst1, 'A', 10);
    
    ret1 = ft_strlcpy(dst1, src1, 10);

    printf("  dst buffer: '%s'\n", dst1);
    printf("  Return val: %zu\n", ret1);
    // Check results
    if (strcmp(dst1, "hello") == 0 && ret1 == 5)
        printf("  PASS!\n");
    else
        printf("  FAIL!\n");

    // --- Test 2: The Truncation Test (The most important!) ---
    printf("\n--- Test 2: Truncation ---\n");
    char    src2[] = "hello world"; // length 11
    char    dst2[10];
    size_t  ret2;

    // Fill dst with 'A's
    memset(dst2, 'A', 10);
    
    // Try to copy 11 chars into a size 6 buffer
    ret2 = ft_strlcpy(dst2, src2, 6); 

    printf("  dst buffer: '%s'\n", dst2);
    printf("  Return val: %zu\n", ret2);
    // Check results
    // dst should be "hello" (size 6 - 1 = 5 chars)
    // ret should be 11 (the length of the *source*)
    if (strcmp(dst2, "hello") == 0 && ret2 == 11)
        printf("  PASS!\n");
    else
        printf("  FAIL!\n");

    // --- Test 3: The size = 0 Test ---
    printf("\n--- Test 3: Size = 0 ---\n");
    char    src3[] = "hello";
    char    dst3[10];
    size_t  ret3;

    memset(dst3, 'A', 10);
    dst3[9] = '\0'; // Just to make printf safe
    
    ret3 = ft_strlcpy(dst3, src3, 0);
    
    printf("  dst[0] should still be 'A': %c\n", dst3[0]);
    printf("  Return val: %zu\n", ret3);
    // Check results
    // dst should be untouched
    // ret should be 5 (length of src)
    if (dst3[0] == 'A' && ret3 == 5)
        printf("  PASS!\n");
    else
        printf("  FAIL!\n");

    return (0);
}