/*
** EPITECH PROJECT, 2023
** layer_config_on_render.c
** File description:
** layer_config_on_render.c
*/

#include "layers/config_impl.h"

void layer_config_on_render(layer_t *layer)
{
    sfRenderWindow_clear(layer_get_window(layer), sfColor_fromRGB(26, 26, 26));
}
