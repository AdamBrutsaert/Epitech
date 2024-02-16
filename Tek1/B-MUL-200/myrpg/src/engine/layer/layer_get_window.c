/*
** EPITECH PROJECT, 2023
** layer_get_window.c
** File description:
** layer_get_window.c
*/

#include "engine/layer_impl.h"

sfRenderWindow *layer_get_window(layer_t *layer)
{
    return engine_get_window(layer->engine);
}
