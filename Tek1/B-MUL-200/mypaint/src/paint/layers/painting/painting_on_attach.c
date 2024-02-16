/*
** EPITECH PROJECT, 2023
** painting_on_attach.c
** File description:
** painting_on_attach.c
*/

#include "private/paint/layers/painting.h"

static bool create(painting_t *painting, context_t *ctx)
{
    painting->canvas = canvas_create(ctx);
    painting->tool = tool_create(ctx, painting->canvas);

    return painting->canvas;
}

bool painting_on_attach(context_t *ctx, void *data)
{
    painting_t *painting = data;

    return create(painting, ctx);
}
