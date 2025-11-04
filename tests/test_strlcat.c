/*
todo:
[x] header
[x] maker
[x] maker_test
[x] testing
*/

#include <stdio.h>
#include <string.h> // For memset, strcpy, and the real strlcat
#include "libft.h"

int test_strlcat(void)
{
    // --- Test 1: Normal Concatenation (Enough space) ---
    printf("tesing strlcat\n--- Test 1: Normal Concat ---\n");
    char    dst1[20];
    char    src1[] = "world"; // len 5
    size_t  ret1;

    // Prepare dst: fill with 'A' and add a starter string "hello "
    memset(dst1, 'A', 20);
    strcpy(dst1, "hello "); // initial_len = 6
    
    // We have "hello " (6) and "world" (5). Total = 11.
    // We give it a total size of 20, which is plenty.
    ret1 = ft_strlcat(dst1, src1, 20);

    printf("  dst buffer: '%s'\n", dst1);
    printf("  Return val: %zu\n", ret1);
    
    // Check results
    // dst should be "hello world"
    // ret should be 6 (initial dst) + 5 (src) = 11
    if (strcmp(dst1, "hello world") == 0 && ret1 == 11)
        printf("  PASS!\n");
    else
        printf("  FAIL! (Check string or return value)\n");


    // --- Test 2: The Truncation Test (Not enough space) ---
    printf("\n--- Test 2: Truncation ---\n");
    char    dst2[20];
    char    src2[] = "world"; // len 5
    size_t  ret2;

    // Prepare dst
    memset(dst2, 'A', 20);
    strcpy(dst2, "hello "); // initial_len = 6
    
    // We give it a total size of 10.
    // It will append 3 chars ("wor") + 1 NUL ('\0').
    // Final string: "hello wor" (length 9)
    ret2 = ft_strlcat(dst2, src2, 10); 

    printf("  dst buffer: '%s'\n", dst2);
    printf("  Return val: %zu\n", ret2);
    
    // Check results
    // dst should be "hello wor"
    // ret should STILL be 6 (initial dst) + 5 (src) = 11
    if (strcmp(dst2, "hello wor") == 0 && ret2 == 11)
        printf("  PASS!\n");
    else
        printf("  FAIL! (Check truncation or return value)\n");


    // --- Test 3: The 'dst is full' Test (size <= strlen(dst)) ---
    printf("\n--- Test 3: Dst is full ---\n");
    char    dst3[20];
    char    src3[] = "world"; // len 5
    size_t  ret3;

    memset(dst3, 'A', 20);
    strcpy(dst3, "hello "); // initial_len = 6
    
    // We give it a size of 4, which is *less than* strlen(dst)
    // It should append nothing.
    ret3 = ft_strlcat(dst3, src3, 4);
    
    printf("  dst buffer: '%s'\n", dst3);
    printf("  Return val: %zu\n", ret3);
    
    // Check results
    // dst should still be "hello "
    // Per the man page, ret should be size + strlen(src)
    // 4 + 5 = 9
    if (strcmp(dst3, "hello ") == 0 && ret3 == 9)
        printf("  PASS!\n");
    else
        printf("  FAIL! (Check 'dst is full' logic)\n");

    return (0);
}