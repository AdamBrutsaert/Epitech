/*
** EPITECH PROJECT, 2023
** layer_get_data.c
** File description:
** layer_get_data.c
*/

#include "private/engine/layer.h"

void *layer_get_data(layer_t *layer)
{
    return layer->data;
}
