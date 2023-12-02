/*
** EPITECH PROJECT, 2023
** menu_on_detach.c
** File description:
** menu_on_detach.c
*/

#include "layers/menu_impl.h"

bool menu_on_event(layer_t *layer, sfEvent *event)
{
    menu_t *menu = layer_get_data(layer);
    sfVector2u size = sfRenderWindow_getSize(layer_get_window(layer));
    sfView *view = layer_get_view(layer);

    if (event->type == sfEvtResized) {
        sfView_setSize(view, (sfVector2f) {size.x, size.y});
        sfView_setCenter(view,
            (sfVector2f) {size.x / 2.0f, size.y / 2.0f});
        text_set_position(menu->title, (sfVector2f) {TEXT_CENTER,
            0.2 * size.y});
        button_set_position(menu->resume, size.x / 2.0f - 203,
            size.y / 2.0f - 71);
        button_set_position(menu->play, size.x / 2.0f - 203,
            size.y / 2.0f - 21);
        button_set_position(menu->config, size.x / 2.0f - 203,
            size.y / 2.0f + 29);
        button_set_position(menu->quit, size.x / 2.0f - 203,
            size.y / 2.0f + 79);
    }
    return true;
}
