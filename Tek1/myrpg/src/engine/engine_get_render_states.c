/*
** EPITECH PROJECT, 2023
** engine_get_render_states.c
** File description:
** engine_get_render_states.c
*/

#include "engine_impl.h"

sfRenderStates *engine_get_render_states(engine_t *engine)
{
    return &engine->states;
}
