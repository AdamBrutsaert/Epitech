/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#define _GNU_SOURCE
#include <string.h>
#include <strings.h>
#include <stdio.h>

void test_strlen(const char *string)
{
    printf("[strlen] \"%s\" -> %zu\n", string, strlen("Hello, World!"));
}

void test_strchr(const char *string, int c)
{
    if (c == '\0') {
        printf("[strchr] \"%s\" '\\0' -> \"%s\"\n", string, strchr(string, c));
    } else {
        printf("[strchr] \"%s\" '%c' -> \"%s\"\n", string, c, strchr(string, c));
    }

}

void test_strrchr(const char *string, int c)
{
    if (c == '\0') {
        printf("[strrchr] \"%s\" '\\0' -> \"%s\"\n", string, strrchr(string, c));
    } else {
        printf("[strrchr] \"%s\" '%c' -> \"%s\"\n", string, c, strrchr(string, c));
    }
}

void test_index(const char *string, int c)
{
    if (c == '\0') {
        printf("[index] \"%s\" '\\0' -> \"%s\"\n", string, index(string, c));
    } else {
        printf("[index] \"%s\" '%c' -> \"%s\"\n", string, c, index(string, c));
    }

}

void test_rindex(const char *string, int c)
{
    if (c == '\0') {
        printf("[rindex] \"%s\" '\\0' -> \"%s\"\n", string, rindex(string, c));
    } else {
        printf("[rindex] \"%s\" '%c' -> \"%s\"\n", string, c, rindex(string, c));
    }
}

void test_memset(const char *memory, int c, size_t n)
{
    printf("[memset] \"%s\" '%c' %zu -> ", memory, c, n);
    const char *v = memset((void *)memory, c, n);
    printf("\"%s\"\n", v);
}

void test_memcpy(char *dest, const char *src, size_t n)
{
    printf("[memcpy] \"%s\" \"%s\" %zu -> ", dest, src, n);
    const char *v = memcpy((void *)dest, (const void *)src, n);
    printf("\"%s\"\n", v);
}

void test_memmove(char *dest, const char *src, size_t n)
{
    printf("[memmove] \"%s\" \"%s\" %zu -> ", dest, src, n);
    const char *v = memmove((void *)dest, (const void *)src, n);
    printf("\"%s\"\n", v);
}

void test_strcmp(const char *s1, const char *s2)
{
    printf("[strcmp] \"%s\" \"%s\" -> %d\n", s1, s2, strcmp(s1, s2));
}

void test_strncmp(const char *s1, const char *s2, size_t n)
{
    printf("[strncmp] \"%s\" \"%s\" -> %d\n", s1, s2, strncmp(s1, s2, n));
}

void test_strcasecmp(const char *s1, const char *s2)
{
    printf("[strcasecmp] \"%s\" \"%s\" -> %d\n", s1, s2, strcasecmp(s1, s2));
}

void test_strstr(const char *haystack, const char *needle)
{
    printf("[strstr] \"%s\" \"%s\" -> \"%s\"\n", haystack, needle, strstr(haystack, needle));
}

void test_strpbrk(const char *s, const char *accept)
{
    printf("[strpbrk] \"%s\" \"%s\" -> \"%s\"\n", s, accept, strpbrk(s, accept));
}

void test_strcspn(const char *s, const char *reject)
{
    printf("[strcspn] \"%s\" \"%s\" -> %zu\n", s, reject, strcspn(s, reject));
}

void test_ffs(int nb)
{
    printf("[ffs] %d -> %d\n", nb, ffs(nb));
}

void test_memfrob(char *buffer, size_t n)
{
    printf("[memfrob] \"%s\" %zu -> ", buffer, n);
    char *v = memfrob((void *)buffer, n);
    printf("\"%s\"\n", v);
}

int main()
{
    test_strlen("Hello, World!");
    test_strlen("Hello 0123");
    test_strlen("");

    test_strchr("Hello, World!", 'W');
    test_strchr("Hello, World!", 'l');
    test_strchr("Hello, World!", 'o');
    test_strchr("Hello, World!", 'x');
    test_strchr("Hello, World!", '\0');

    test_strrchr("Hello, World!", 'W');
    test_strrchr("Hello, World!", 'l');
    test_strrchr("Hello, World!", 'o');
    test_strrchr("Hello, World!", 'x');
    test_strrchr("Hello, World!", '\0');

    test_index("Hello, World!", 'W');
    test_index("Hello, World!", 'l');
    test_index("Hello, World!", 'o');
    test_index("Hello, World!", 'x');
    test_index("Hello, World!", '\0');

    test_rindex("Hello, World!", 'W');
    test_rindex("Hello, World!", 'l');
    test_rindex("Hello, World!", 'o');
    test_rindex("Hello, World!", 'x');
    test_rindex("Hello, World!", '\0');

    test_memset((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, 'x', 5);
    test_memset((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, 'y', 0);
    test_memset((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, 'z', 13);
    test_memset((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, 69420, 13);

    test_memcpy((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, "Hello, World!", 13);
    test_memcpy((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, "test", 4);
    test_memcpy((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, "test", 5);
    test_memcpy((char []){ 'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0' }, "test", 0);

    char dest[] = "Hello, world!";
    test_memmove(dest, dest + 3, 5);
    test_memmove(dest, dest + 3, 0);
    test_memmove(dest + 3, dest, 5);
    test_memmove(dest + 3, dest, 0);

    test_strcmp("Hello, World!", "Hello, World!");
    test_strcmp("Hello, World!", "Hello, France!");
    test_strcmp("Hello, France!", "Hello, World!");
    test_strcmp("Hello, World! ", "Hello, World!");
    test_strcmp("Hello, World!", "Hello, World! ");

    test_strncmp("Hello, World!", "Hello, World!", 13);
    test_strncmp("Hello, World!", "Hello, France!", 13);
    test_strncmp("Hello, France!", "Hello, World!", 13);
    test_strncmp("Hello, World!", "Hello, France!", 5);
    test_strncmp("Hello, World!", "Hello, World!", 0);

    test_strcasecmp("Hello, World!", "Hello, World!");
    test_strcasecmp("Hello, World!", "hello, WORLD!");
    test_strcasecmp("Hello, World!", "Hello, France!");
    test_strcasecmp("HElloo, World!", "heLLO!");

    test_strstr("Hello, World!", "World");
    test_strstr("Hello, World!", "");
    test_strstr("Hello, World!", "notinthere");
    test_strstr("Hello, World!", "e");
    test_strstr("", "");
    test_strstr("", "test");

    test_strpbrk("Hello, World!", "abcd");
    test_strpbrk("Hello, World!", "xz");
    test_strpbrk("Hello, World!", "");

    test_strcspn("Hello, World!", "abcd");
    test_strcspn("Hello, World!", "Hel");
    test_strcspn("Hello, World!", "");
    test_strcspn("Hello, World!", "Wo");
    test_strcspn("", "");

    test_ffs(0);
    test_ffs(1);
    test_ffs(2);
    test_ffs(3);
    test_ffs(4);
    test_ffs(8);
    test_ffs(16);
    test_ffs(24);
    test_ffs(-1);

    char buffer1[] = "hguesbgesbi";
    char buffer2[] = "4Y3 '48 '\"";
    test_memfrob(buffer1, 11);
    test_memfrob(buffer2, 10);

    return 0;
}
