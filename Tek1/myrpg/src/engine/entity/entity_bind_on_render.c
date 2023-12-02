/*
** EPITECH PROJECT, 2023
** entity_bind_on_render.c
** File description:
** entity_bind_on_render.c
*/

#include "engine/entity_impl.h"

void entity_bind_on_render(entity_t *entity, entity_on_render_t on_render)
{
    entity->on_render = on_render;
}
