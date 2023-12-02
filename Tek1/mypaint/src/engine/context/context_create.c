/*
** EPITECH PROJECT, 2023
** context_create.c
** File description:
** context_create.c
*/

#include "private/engine/context.h"
#include "my/memory.h"

static bool create(context_t *ctx, uint32_t width, uint32_t height,
    const char *title)
{
    ctx->window = sfRenderWindow_create((sfVideoMode){width, height, 32},
        title, sfDefaultStyle, NULL);
    ctx->view = sfView_create();
    return ctx->window && ctx->view;
}

static void set(context_t *ctx)
{
    sfVector2u size = sfRenderWindow_getSize(ctx->window);

    sfView_setCenter(ctx->view, (sfVector2f){size.x / 2.0f, size.y / 2.0f});
    sfView_setSize(ctx->view, (sfVector2f){size.x, size.y});
    sfRenderWindow_setView(ctx->window, ctx->view);
}

context_t *context_create(uint32_t width, uint32_t height, const char *title)
{
    context_t *ctx = my_calloc(sizeof(context_t));

    if (!ctx)
        return NULL;
    if (!create(ctx, width, height, title)) {
        context_destroy(ctx);
        return NULL;
    }
    set(ctx);
    return ctx;
}
