/*
** EPITECH PROJECT, 2024
** string_create_random_uuid.c
** File description:
** string_create_random_uuid.c
*/

#include "my/memory/string.h"

#include <uuid/uuid.h>

string_t *string_create_random_uuid(void)
{
    uuid_t uuid;
    char buffer[UUID_STR_LEN];

    uuid_generate_random(uuid);
    uuid_unparse_lower(uuid, buffer);
    return string_create_from_cstr(buffer);
}
