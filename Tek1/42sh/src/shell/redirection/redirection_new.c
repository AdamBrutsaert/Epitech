/*
** EPITECH PROJECT, 2023
** redirection_new.c
** File description:
** redirection_new.c
*/

#include "shell/redirection_impl.h"

#include <stdlib.h>
#include <string.h>

redirection_t *redirection_new(redirection_type_t type, const char *value)
{
    redirection_t *redirection = calloc(1, sizeof(redirection_t));

    if (redirection == NULL)
        return NULL;
    redirection->type = type;
    redirection->value = strdup(value);
    if (redirection->value == NULL) {
        redirection_delete(redirection);
        return NULL;
    }
    return redirection;
}
