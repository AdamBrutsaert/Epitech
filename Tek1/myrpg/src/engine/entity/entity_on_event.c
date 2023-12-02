/*
** EPITECH PROJECT, 2023
** entity_on_event.c
** File description:
** entity_on_event.c
*/

#include "engine/entity_impl.h"

bool entity_on_event(entity_t *entity, sfEvent *event)
{
    if (entity->on_event != NULL)
        return entity->on_event(entity, event);
    return true;
}
