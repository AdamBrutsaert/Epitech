/*
** EPITECH PROJECT, 2024
** concat.c
** File description:
** concat.c
*/

#include "concat.h"

#include <stdlib.h>
#include <string.h>

void concat_strings(const char *str1, const char *str2, char **res)
{
    *res = calloc(strlen(str1) + strlen(str2) + 1, sizeof(char));
    if (*res != NULL) {
        strcat(*res, str1);
        strcat(*res, str2);
    }
}

void concat_struct(concat_t *str)
{
    concat_strings(str->str1, str->str2, &str->res);
}
