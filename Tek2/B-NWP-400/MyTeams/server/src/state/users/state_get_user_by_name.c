/*
** EPITECH PROJECT, 2024
** state_get_user_by_name.c
** File description:
** state_get_user_by_name.c
*/

#include "state.h"

user_t *state_get_user_by_name(state_t *self, const string_t *name)
{
    user_t *current;

    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        current = *(user_t **)VEC_AT(self->users, i);
        if (string_compare(current->name, name) == 0)
            return current;
    }
    return nullptr;
}
