/*
** EPITECH PROJECT, 2023
** menu_bind_canvas.c
** File description:
** menu_bind_canvas.c
*/

#include "private/paint/layers/menu.h"

void menu_bind_canvas(layer_t *layer, canvas_t *canvas)
{
    menu_t *menu = layer_get_data(layer);

    menu->canvas = canvas;
}
