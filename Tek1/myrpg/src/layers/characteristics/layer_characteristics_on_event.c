/*
** EPITECH PROJECT, 2023
** layer_characteristics_on_event.c
** File description:
** layer_characteristics_on_event.c
*/

#include "layers/characteristics_impl.h"

bool layer_characteristics_on_event(layer_t *layer, sfEvent *event)
{
    sfView *view = layer_get_view(layer);

    if (event->type == sfEvtResized) {
        sfView_setSize(view, (sfVector2f){event->size.width,
            event->size.height});
        sfView_setCenter(view, (sfVector2f){event->size.width / 2.0f,
            event->size.height / 2.0f});
    }
    return true;
}
