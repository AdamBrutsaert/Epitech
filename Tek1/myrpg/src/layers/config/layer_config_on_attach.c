/*
** EPITECH PROJECT, 2023
** layer_config_on_attach.c
** File description:
** layer_config_on_attach.c
*/

#include "layers/config_impl.h"

bool layer_config_on_attach(layer_t *layer)
{
    layer_config_t *config = layer_get_data(layer);
    sfRenderWindow *window = layer_get_window(layer);
    sfVector2u window_size = sfRenderWindow_getSize(window);
    sfView *view = layer_get_view(layer);

    sfView_setSize(view, (sfVector2f) {window_size.x, window_size.y});
    sfView_setCenter(view, (sfVector2f) {window_size.x / 2, window_size.y / 2});
    config->font = sfFont_createFromFile(RES("font/dogica.ttf"));
    if (!config->font || !layer_config_add_buttons(layer, config))
        return false;
    return true;
}
