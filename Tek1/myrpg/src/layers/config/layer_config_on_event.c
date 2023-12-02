/*
** EPITECH PROJECT, 2023
** layer_config_on_event.c
** File description:
** layer_config_on_event.c
*/

#include "layers/config_impl.h"
#include "entities/button.h"

bool layer_config_on_event(layer_t *layer, sfEvent *event)
{
    sfVector2u window_size = sfRenderWindow_getSize(layer_get_window(layer));
    sfView *view = layer_get_view(layer);

    if (event->type == sfEvtResized) {
        sfView_setSize(view, (sfVector2f){window_size.x, window_size.y});
        sfView_setCenter(view,
            (sfVector2f) {window_size.x / 2, window_size.y / 2});
        layer_config_center_buttons(layer);
    } else {
        engine_prevent_propagation(layer_get_engine(layer));
    }
    if (event->type == sfEvtKeyPressed && event->key.code == sfKeyEscape)
        engine_pop_layer(layer_get_engine(layer));
    return true;
}
