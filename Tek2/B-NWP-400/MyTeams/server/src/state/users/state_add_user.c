/*
** EPITECH PROJECT, 2024
** state_add_user.c
** File description:
** state_add_user.c
*/

#include "state.h"

void state_add_user(state_t *self, user_t *user)
{
    vec_push_back(self->users, &user);
}
