/*
** EPITECH PROJECT, 2023
** entity_on_detach.c
** File description:
** entity_on_detach.c
*/

#include "engine/entity_impl.h"

void entity_on_detach(entity_t *entity)
{
    if (entity->on_detach != NULL)
        entity->on_detach(entity);
}
