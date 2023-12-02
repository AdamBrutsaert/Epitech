/*
** EPITECH PROJECT, 2023
** context_run.c
** File description:
** context_run.c
*/

#include "private/engine/context.h"

bool context_run(context_t *ctx)
{
    sfClock *clock = sfClock_create();

    if (!clock)
        return false;
    while (sfRenderWindow_isOpen(ctx->window)) {
        if (!context_handle_events(ctx))
            return false;
        if (!context_update(ctx, sfTime_asSeconds(sfClock_restart(clock))))
            return false;
        sfRenderWindow_clear(ctx->window, sfBlack);
        if (!context_render(ctx))
            return false;
        sfRenderWindow_display(ctx->window);
    }
    sfClock_destroy(clock);
    return true;
}
