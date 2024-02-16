/*
** EPITECH PROJECT, 2023
** entity_skeleton_new.c
** File description:
** entity_skeleton_new.c
*/

#include "engine/entity.h"
#include "entities/skeleton_impl.h"

entity_t *entity_skeleton_new(sfVector2f pos)
{
    entity_t *entity = entity_new(sizeof(entity_skeleton_t));
    entity_skeleton_t *data;

    if (entity == NULL)
        return NULL;
    data = entity_get_data(entity);
    data->pos = pos;
    entity_set_type(entity, "Skeleton");
    entity_bind_on_attach(entity, entity_skeleton_on_attach);
    entity_bind_on_detach(entity, entity_skeleton_on_detach);
    entity_bind_on_event(entity, entity_skeleton_on_event);
    entity_bind_on_update(entity, entity_skeleton_on_update);
    entity_bind_on_render(entity, entity_skeleton_on_render);
    return entity;
}
