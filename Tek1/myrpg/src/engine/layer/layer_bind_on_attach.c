/*
** EPITECH PROJECT, 2023
** layer_bind_on_attach.c
** File description:
** layer_bind_on_attach.c
*/

#include "engine/layer_impl.h"

void layer_bind_on_attach(layer_t *layer, layer_on_attach_t on_attach)
{
    layer->on_attach = on_attach;
}
