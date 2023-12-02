/*
** EPITECH PROJECT, 2023
** layer_bind_on_event.c
** File description:
** layer_bind_on_event.c
*/

#include "engine/layer_impl.h"

void layer_bind_on_event(layer_t *layer, layer_on_event_t on_event)
{
    layer->on_event = on_event;
}
