/*
** EPITECH PROJECT, 2023
** entity_bind_on_update.c
** File description:
** entity_bind_on_update.c
*/

#include "engine/entity_impl.h"

void entity_bind_on_update(entity_t *entity, entity_on_update_t on_update)
{
    entity->on_update = on_update;
}
