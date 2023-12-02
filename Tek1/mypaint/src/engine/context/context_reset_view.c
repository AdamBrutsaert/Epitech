/*
** EPITECH PROJECT, 2023
** context_reset_view.c
** File description:
** context_reset_view.c
*/

#include "private/engine/context.h"

void context_reset_view(context_t *ctx)
{
    sfRenderWindow_setView(ctx->window, ctx->view);
}
