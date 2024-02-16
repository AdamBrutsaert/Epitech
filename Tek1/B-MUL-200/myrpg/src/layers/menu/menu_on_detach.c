/*
** EPITECH PROJECT, 2023
** menu_on_detach.c
** File description:
** menu_on_detach.c
*/

#include "layers/menu_impl.h"

#include <stdio.h>

void menu_on_detach(layer_t *layer)
{
    menu_t *menu = layer_get_data(layer);

    sfFont_destroy(menu->font);
    sfMusic_destroy(menu->music);
}
