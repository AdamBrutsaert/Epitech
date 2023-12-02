/*
** EPITECH PROJECT, 2023
** context_get_window.c
** File description:
** context_get_window.c
*/

#include "private/engine/context.h"

sfRenderWindow *context_get_window(context_t *ctx)
{
    return ctx->window;
}
