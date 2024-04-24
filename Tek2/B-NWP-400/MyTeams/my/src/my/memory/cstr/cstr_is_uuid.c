/*
** EPITECH PROJECT, 2024
** cstr_is_uuid.c
** File description:
** cstr_is_uuid.c
*/

#include "my/memory/cstr.h"

#include <uuid/uuid.h>

bool cstr_is_uuid(const char *cstr)
{
    uuid_t binuuid;

    return uuid_parse(cstr, binuuid) != -1;
}
