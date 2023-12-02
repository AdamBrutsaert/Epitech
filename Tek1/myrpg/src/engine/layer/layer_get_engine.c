/*
** EPITECH PROJECT, 2023
** layer_get_engine.c
** File description:
** layer_get_engine.c
*/

#include "engine/layer_impl.h"

struct engine *layer_get_engine(layer_t *layer)
{
    return layer->engine;
}
