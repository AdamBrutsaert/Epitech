/*
** EPITECH PROJECT, 2023
** layer_characteristics_on_render.c
** File description:
** layer_characteristics_on_render.c
*/

#include "layers/characteristics_impl.h"

void layer_characteristics_on_render(layer_t *layer)
{
    layer_characteristics_t *data = layer_get_data(layer);
    sfRenderWindow *window = layer_get_window(layer);

    for (size_t i = 0; i < data->max_life; i++)
        sfRenderWindow_drawSprite(window, data->hearts[i], NULL);
}
