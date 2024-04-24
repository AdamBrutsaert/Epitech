/*
** EPITECH PROJECT, 2024
** state_get_user_by_uuid.c
** File description:
** state_get_user_by_uuid.c
*/

#include "state.h"

user_t *state_get_user_by_uuid(state_t *self, const string_t *uuid)
{
    user_t *current;

    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        current = *(user_t **)VEC_AT(self->users, i);
        if (string_compare(current->uuid, uuid) == 0)
            return current;
    }
    return nullptr;
}
