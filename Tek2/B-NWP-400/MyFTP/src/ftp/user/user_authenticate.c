/*
** EPITECH PROJECT, 2024
** user_authenticate.c
** File description:
** user_authenticate.c
*/

#include "ftp/user.h"

#include <string.h>

void user_authenticate(user_t *self, const char *password)
{
    if (!strcmp(self->name, "Anonymous")
        && (password == NULL || !strcmp(password, ""))) {
        self->authed = true;
    }
}
