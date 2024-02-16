/*
** EPITECH PROJECT, 2023
** layer_set_engine.c
** File description:
** layer_set_engine.c
*/

#include "engine/layer_impl.h"

void layer_set_engine(layer_t *layer, engine_t *engine)
{
    layer->engine = engine;
}
