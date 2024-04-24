/*
** EPITECH PROJECT, 2024
** user_create.c
** File description:
** user_create.c
*/

#include "protocol/entities/user.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

user_t *user_create(const string_t *name)
{
    user_t *user = allocate(sizeof(user_t));

    user->uuid = string_create_random_uuid();
    user->name = string_clone_n(name, MAX_NAME_LENGTH);
    user->connections = 0;
    return user;
}
