/*
** EPITECH PROJECT, 2023
** context_push.c
** File description:
** context_push.c
*/

#include "private/engine/context.h"
#include "private/engine/layer.h"
#include "my/memory.h"

static bool grow(context_t *ctx)
{
    size_t capacity = ctx->layers_capacity * 2 + !ctx->layers_capacity;
    layer_t **layers = my_realloc(ctx->layers, capacity * sizeof(layer_t *));

    if (!layers)
        return false;
    ctx->layers = layers;
    ctx->layers_capacity = capacity;
    return true;
}

bool context_push(context_t *ctx, layer_t *layer)
{
    if (ctx->layers_length == ctx->layers_capacity && !grow(ctx))
        return false;
    if (!layer_on_attach(layer, ctx)) {
        layer_on_detach(layer, ctx);
        return false;
    }
    ctx->layers[ctx->layers_length] = layer;
    ctx->layers_length++;
    return true;
}
