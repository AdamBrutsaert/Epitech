/*
** EPITECH PROJECT, 2023
** layer_get_render_states.c
** File description:
** layer_get_render_states.c
*/

#include "engine/layer_impl.h"

sfRenderStates *layer_get_render_states(layer_t *layer)
{
    return engine_get_render_states(layer_get_engine(layer));
}
