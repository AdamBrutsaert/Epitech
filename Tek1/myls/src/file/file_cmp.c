/*
** EPITECH PROJECT, 2022
** file_cmp.c
** File description:
** file_cmp.c
*/

#include "my/details/file.h"

int file_cmp_name(file_t *f1, file_t *f2)
{
    char const *s1 = f1->name + (*f1->name == '.');
    char const *s2 = f2->name + (*f2->name == '.');
    unsigned char c1 = *s1;
    unsigned char c2 = *s2;

    while (*s1 && *s2) {
        c1 = *s1 + 32 * (*s1 >= 'A' && *s1 <= 'Z');
        c2 = *s2 + 32 * (*s2 >= 'A' && *s2 <= 'Z');
        if (c1 != c2)
            break;
        s1++;
        s2++;
    }
    c1 = *s1 + 32 * (*s1 >= 'A' && *s1 <= 'Z');
    c2 = *s2 + 32 * (*s2 >= 'A' && *s2 <= 'Z');
    return c1 - c2;
}

int file_cmp_rev_name(file_t *f1, file_t *f2)
{
    return -file_cmp_name(f1, f2);
}

int file_cmp_timestamp(file_t *f1, file_t *f2)
{
    if (f1->last_modification < f2->last_modification)
        return 1;
    if (f1->last_modification > f2->last_modification)
        return -1;
    return file_cmp_name(f1, f2);
}

int file_cmp_rev_timestamp(file_t *f1, file_t *f2)
{
    if (f1->last_modification < f2->last_modification)
        return -1;
    if (f1->last_modification > f2->last_modification)
        return 1;
    return file_cmp_rev_name(f1, f2);
}
