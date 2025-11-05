#include <stdio.h>  // For printf
#include <string.h> // For strcmp and strcpy
#include <stdlib.h> // For size_t
#include "../libft.h" // Include your main header

/*
* This is a static helper function for checking.
* It compares the modified string 's1' to the 'expected' string.
*/
static void check(const char *test_name, const char *s1, const char *expected)
{
    // strcmp returns 0 if the strings are identical
    if (strcmp(s1, expected) == 0)
    {
        printf("  [PASS] %s\n", test_name);
    }
    else
    {
        printf("  [FAIL] %s: Expected '%s', got '%s'\n", 
            test_name, expected, s1);
    }
}

/*
* This is a simple 'iterator' function we will pass to ft_striteri.
* It modifies the character by adding its index to it.
*/
static void iter_add_index(unsigned int i, char *c)
{
    // *c is the character. We add 'i' to it.
    *c = *c + i;
}

/*
* This is the main test function that your main.c will call.
*/
void test_striteri(void)
{
    // We MUST use a writable char array, not a const char*
    char    str[50];

    printf("\n--- Testing ft_striteri ---\n");

    // --- Test 1: Basic modification ---
    strcpy(str, "aaaaa"); // Set up the string
    ft_striteri(str, &iter_add_index);
    check("Modify 'aaaaa'", str, "abcde");

    // --- Test 2: Empty string ---
    strcpy(str, ""); // Set up an empty string
    ft_striteri(str, &iter_add_index);
    check("Empty string", str, "");

    // --- Test 3: 's' is NULL (CRITICAL) ---
    // This test just checks that your function doesn't segfault.
    printf("  Testing 's' is NULL...");
    ft_striteri(NULL, &iter_add_index);
    printf(" [PASS] (Did not crash)\n"); // If it didn't crash, it passed

    // --- Test 4: 'f' is NULL (CRITICAL) ---
    // This also just checks for a segfault.
    printf("  Testing 'f' is NULL...");
    strcpy(str, "hello");
    ft_striteri(str, NULL);
    printf(" [PASS] (Did not crash)\n");
    check("... and 'f' is NULL did not modify string", str, "hello");

    printf("---------------------------\n");
}