/*
** EPITECH PROJECT, 2023
** layer_bind_on_detach.c
** File description:
** layer_bind_on_detach.c
*/

#include "engine/layer_impl.h"

void layer_bind_on_detach(layer_t *layer, layer_on_detach_t on_detach)
{
    layer->on_detach = on_detach;
}
