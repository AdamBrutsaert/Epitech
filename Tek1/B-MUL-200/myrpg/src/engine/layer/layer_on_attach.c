/*
** EPITECH PROJECT, 2023
** layer_on_attach.c
** File description:
** layer_on_attach.c
*/

#include "engine/layer_impl.h"

bool layer_on_attach(layer_t *layer)
{
    if (layer->on_attach != NULL)
        return layer->on_attach(layer);
    return true;
}
