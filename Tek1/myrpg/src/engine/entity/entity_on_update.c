/*
** EPITECH PROJECT, 2023
** entity_on_update.c
** File description:
** entity_on_update.c
*/

#include "engine/entity_impl.h"

bool entity_on_update(entity_t *entity, float dt)
{
    if (entity->on_update != NULL)
        return entity->on_update(entity, dt);
    return true;
}
