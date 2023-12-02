/*
** EPITECH PROJECT, 2023
** entity_new.c
** File description:
** entity_new.c
*/

#include "engine/entity_impl.h"
#include "my/memory.h"

entity_t *entity_new(size_t data_size)
{
    entity_t *entity = my_calloc(sizeof(entity_t));

    if (entity == NULL)
        return NULL;
    entity->data = my_calloc(data_size);
    if (entity->data == NULL && data_size != 0) {
        entity_delete(entity);
        return NULL;
    }
    entity->type = ENTITY_UNKNOWN_TYPE;
    return entity;
}
