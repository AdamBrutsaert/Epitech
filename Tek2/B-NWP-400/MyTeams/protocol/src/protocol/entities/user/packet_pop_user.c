/*
** EPITECH PROJECT, 2024
** packet_pop_user.c
** File description:
** packet_pop_user.c
*/

#include "protocol/entities/user.h"

#include "my/memory/allocation.h"

bool packet_pop_user(packet_t *self, user_t **user)
{
    uint64_t connections;
    string_t *name;
    string_t *uuid;

    if (!packet_pop_u64(self, &connections) || !packet_pop_string(self, &name))
        return false;
    if (!packet_pop_string(self, &uuid)) {
        string_destroy(name);
        return false;
    }
    *user = allocate(sizeof(user_t));
    **user = (user_t){uuid, name, connections};
    return true;
}
