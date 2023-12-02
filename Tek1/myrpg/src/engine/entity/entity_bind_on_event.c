/*
** EPITECH PROJECT, 2023
** entity_bind_on_event.c
** File description:
** entity_bind_on_event.c
*/

#include "engine/entity_impl.h"

void entity_bind_on_event(entity_t *entity, entity_on_event_t on_event)
{
    entity->on_event = on_event;
}
