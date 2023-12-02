/*
** EPITECH PROJECT, 2023
** hand_on_update.c
** File description:
** hand_on_update.c
*/

#include "private/paint/components/tools/hand.h"

bool hand_on_update(context_t *ctx, hand_t *hand,
    __attribute__((unused)) float dt)
{
    sfVector2i current =
        sfMouse_getPositionRenderWindow(context_get_window(ctx));

    if (hand->is_pressing) {
        canvas_move(hand->canvas, (sfVector2f) {
            hand->last_position.x - current.x,
            hand->last_position.y - current.y
        });
        hand->last_position = current;
    }
    return true;
}
