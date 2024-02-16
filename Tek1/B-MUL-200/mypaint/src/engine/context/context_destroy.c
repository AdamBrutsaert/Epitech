/*
** EPITECH PROJECT, 2023
** context_destroy.c
** File description:
** context_destroy.c
*/

#include "private/engine/context.h"
#include "private/engine/layer.h"
#include "my/memory.h"

void context_destroy(context_t *ctx)
{
    if (!ctx)
        return;
    for (size_t i = 0; i < ctx->layers_length; i++)
        layer_on_detach(ctx->layers[i], ctx);
    sfRenderWindow_destroy(ctx->window);
    my_free(ctx->layers);
    my_free(ctx);
}
