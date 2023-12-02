/*
** EPITECH PROJECT, 2023
** layer_ingame_inventory_on_event.c
** File description:
** layer_ingame_inventory_on_event.c
*/

#include "layers/ingame_inventory_impl.h"

bool layer_ingame_inventory_on_event(layer_t *layer, sfEvent *event)
{
    sfVector2u window_size = sfRenderWindow_getSize(layer_get_window(layer));
    sfView *view = layer_get_view(layer);

    if (event->type == sfEvtResized) {
        sfView_setSize(view, (sfVector2f) {window_size.x, window_size.y});
        sfView_setCenter(view, (sfVector2f) {window_size.x / 2,
            window_size.y / 2});
    }
    return true;
}
