/*
** EPITECH PROJECT, 2023
** layer_settings_on_render.c
** File description:
** layer_settings_on_render.c
*/

#include "layers/settings_impl.h"

void layer_settings_on_render(layer_t *layer)
{
    sfRenderWindow *window = layer_get_window(layer);

    sfRenderWindow_clear(window, sfColor_fromRGB(26, 26, 26));
}
