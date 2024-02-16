/*
** EPITECH PROJECT, 2023
** menu_on_detach.c
** File description:
** menu_on_detach.c
*/

#include "layers/menu_impl.h"

void menu_on_render(layer_t *layer)
{
    sfRenderWindow *window = layer_get_window(layer);

    sfRenderWindow_clear(window, sfColor_fromRGB(28, 28, 28));
}
