/*
** EPITECH PROJECT, 2023
** context_update.c
** File description:
** context_update.c
*/

#include "private/engine/context.h"
#include "private/engine/layer.h"

bool context_update(context_t *ctx, float delta)
{
    for (size_t i = 0; i < ctx->layers_length; i++) {
        if (!layer_on_update(ctx->layers[ctx->layers_length - 1 - i], ctx,
            delta))
            return false;
    }
    return true;
}
