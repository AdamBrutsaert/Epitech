/*
** EPITECH PROJECT, 2023
** layer_characteristics_on_detach.c
** File description:
** layer_characteristics_on_detach.c
*/

#include "layers/characteristics_impl.h"

#include <stdlib.h>

void layer_characteristics_on_detach(layer_t *layer)
{
    layer_characteristics_t *data = layer_get_data(layer);

    for (size_t i = 0; i < data->max_life; i++)
        sfSprite_destroy(data->hearts[i]);
    free(data->hearts);
    sfTexture_destroy(data->texture);
}
