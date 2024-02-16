/*
** EPITECH PROJECT, 2023
** hand_on_event.c
** File description:
** hand_on_event.c
*/

#include "private/paint/components/tools/hand.h"

bool hand_on_event(__attribute__((unused)) context_t *ctx, hand_t *hand,
    sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        hand->is_pressing = true;
        hand->last_position =
            (sfVector2i){event->mouseButton.x, event->mouseButton.y};
    }
    if (event->type == sfEvtMouseButtonReleased)
        hand->is_pressing = false;
    return true;
}
