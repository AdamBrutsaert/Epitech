/*
** EPITECH PROJECT, 2024
** cstr_to_u8.c
** File description:
** cstr_to_u8.c
*/

#include "my/memory/cstr.h"

bool cstr_to_u8(const char *cstr, uint8_t *value)
{
    uint64_t tmp;

    if (!cstr_to_u64(cstr, &tmp))
        return false;
    *value = tmp;
    return tmp <= UINT8_MAX;
}
