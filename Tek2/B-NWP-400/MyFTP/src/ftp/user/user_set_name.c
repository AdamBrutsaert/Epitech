/*
** EPITECH PROJECT, 2024
** user_set_name.c
** File description:
** user_set_name.c
*/

#include "ftp/user.h"

#include <stdlib.h>
#include <string.h>

bool user_set_name(user_t *self, const char *name)
{
    free(self->name);
    if (name == NULL) {
        self->name = NULL;
        return true;
    }
    self->name = strdup(name);
    return self->name != NULL;
}
