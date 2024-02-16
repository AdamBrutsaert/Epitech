/*
** EPITECH PROJECT, 2023
** context_render.c
** File description:
** context_render.c
*/

#include "private/engine/context.h"
#include "private/engine/layer.h"

bool context_render(context_t *ctx)
{
    for (size_t i = 0; i < ctx->layers_length; i++) {
        if (!layer_on_render(ctx->layers[i], ctx))
            return false;
    }
    return true;
}
