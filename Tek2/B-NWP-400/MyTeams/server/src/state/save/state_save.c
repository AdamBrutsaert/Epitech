/*
** EPITECH PROJECT, 2024
** state_save.c
** File description:
** state_save.c
*/

#include "state.h"

void state_save(state_t *self)
{
    state_save_users(self);
    state_save_messages(self);
    state_save_teams(self);
    state_save_team_subscriptions(self);
    state_save_channels(self);
    state_save_threads(self);
    state_save_replies(self);
}
