/*
** EPITECH PROJECT, 2023
** entity_map_new.c
** File description:
** entity_map_new.c
*/

#include "entities/map_impl.h"

entity_t *entity_map_new(const char *map, const char *collisions)
{
    entity_t *entity = entity_new(sizeof(entity_map_t));
    entity_map_t *data;

    if (entity == NULL)
        return NULL;
    data = entity_get_data(entity);
    data->map = map;
    data->collisions = collisions;
    entity_bind_on_attach(entity, entity_map_on_attach);
    entity_bind_on_detach(entity, entity_map_on_detach);
    entity_bind_on_event(entity, entity_map_on_event);
    entity_bind_on_update(entity, entity_map_on_update);
    entity_bind_on_render(entity, entity_map_on_render);
    return entity;
}
