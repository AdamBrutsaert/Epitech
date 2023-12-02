/*
** EPITECH PROJECT, 2023
** redirection_delete.c
** File description:
** redirection_delete.c
*/

#include "shell/redirection_impl.h"

#include <stdlib.h>

void redirection_delete(redirection_t *redirection)
{
    if (redirection == NULL)
        return;
    free(redirection->value);
    free(redirection);
}
