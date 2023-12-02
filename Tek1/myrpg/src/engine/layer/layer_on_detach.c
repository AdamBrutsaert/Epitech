/*
** EPITECH PROJECT, 2023
** layer_on_detach.c
** File description:
** layer_on_detach.c
*/

#include "engine/layer_impl.h"

void layer_on_detach(layer_t *layer)
{
    if (layer->on_detach != NULL)
        layer->on_detach(layer);
}
