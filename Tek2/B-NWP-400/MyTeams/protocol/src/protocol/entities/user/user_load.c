/*
** EPITECH PROJECT, 2024
** user_load.c
** File description:
** user_load.c
*/

#include "protocol/entities/user.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

user_t *user_load(const string_t *uuid, const string_t *name)
{
    user_t *user = allocate(sizeof(user_t));

    user->uuid = string_clone(uuid);
    user->name = string_clone_n(name, MAX_NAME_LENGTH);
    user->connections = 0;
    return user;
}
