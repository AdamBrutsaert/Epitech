/*
** EPITECH PROJECT, 2024
** cstr_to_u64.c
** File description:
** cstr_to_u64.c
*/

#include "my/memory/cstr.h"

#include <stdlib.h>

bool cstr_to_u64(const char *cstr, uint64_t *value)
{
    char *endptr;

    *value = strtoull(cstr, &endptr, 10);
    return *endptr == '\0';
}
