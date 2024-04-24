/*
** EPITECH PROJECT, 2024
** cstr_to_u16.c
** File description:
** cstr_to_u16.c
*/

#include "my/memory/cstr.h"

bool cstr_to_u16(const char *cstr, uint16_t *value)
{
    uint64_t tmp;

    if (!cstr_to_u64(cstr, &tmp))
        return false;
    *value = tmp;
    return tmp <= UINT16_MAX;
}
