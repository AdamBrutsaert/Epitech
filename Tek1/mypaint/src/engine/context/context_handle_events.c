/*
** EPITECH PROJECT, 2023
** context_handle_events.c
** File description:
** context_handle_events.c
*/

#include "private/engine/context.h"
#include "private/engine/layer.h"

static void update_view(context_t *ctx, sfEvent *event)
{
    sfView_setCenter(ctx->view, (sfVector2f){event->size.width / 2.0f,
        event->size.height / 2.0f});
    sfView_setSize(ctx->view, (sfVector2f){event->size.width,
        event->size.height});
    sfRenderWindow_setView(ctx->window, ctx->view);
}

static bool handle_event(context_t *ctx, sfEvent *event)
{
    if (event->type == sfEvtClosed)
        sfRenderWindow_close(ctx->window);
    if (event->type == sfEvtResized)
        update_view(ctx, event);
    for (size_t i = 0; i < ctx->layers_length; i++) {
        if (!layer_on_event(ctx->layers[ctx->layers_length - 1 - i], ctx,
            event))
            return false;
        if (ctx->prevent_propagation) {
            ctx->prevent_propagation = false;
            break;
        }
    }
    return true;
}

bool context_handle_events(context_t *ctx)
{
    sfEvent event;

    for (size_t i = 0; i < ctx->layers_to_pop && ctx->layers_length; i++) {
        layer_on_detach(ctx->layers[ctx->layers_length], ctx);
        ctx->layers_length--;
    }
    ctx->layers_to_pop = 0;
    while (sfRenderWindow_pollEvent(ctx->window, &event)) {
        if (!handle_event(ctx, &event))
            return false;
    }
    return true;
}
