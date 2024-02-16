/*
** EPITECH PROJECT, 2023
** entity_get_render_states.c
** File description:
** entity_get_render_states.c
*/

#include "engine/entity_impl.h"
#include "engine.h"

sfRenderStates *entity_get_render_states(entity_t *entity)
{
    return engine_get_render_states(entity_get_engine(entity));
}
