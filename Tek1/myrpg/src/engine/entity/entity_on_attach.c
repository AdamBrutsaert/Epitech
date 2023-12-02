/*
** EPITECH PROJECT, 2023
** entity_on_attach.c
** File description:
** entity_on_attach.c
*/

#include "engine/entity_impl.h"

bool entity_on_attach(entity_t *entity)
{
    if (entity->on_attach != NULL)
        return entity->on_attach(entity);
    return true;
}
