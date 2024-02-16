/*
** EPITECH PROJECT, 2023
** entity_on_render.c
** File description:
** entity_on_render.c
*/

#include "engine/entity_impl.h"

void entity_on_render(entity_t *entity)
{
    if (entity->on_render)
        entity->on_render(entity);
}
