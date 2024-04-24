/*
** EPITECH PROJECT, 2024
** state_restore.c
** File description:
** state_restore.c
*/

#include "state.h"

void state_restore(state_t *self)
{
    state_restore_users(self);
    state_restore_messages(self);
    state_restore_teams(self);
    state_restore_team_subscriptions(self);
    state_restore_channels(self);
    state_restore_threads(self);
    state_restore_replies(self);
}
