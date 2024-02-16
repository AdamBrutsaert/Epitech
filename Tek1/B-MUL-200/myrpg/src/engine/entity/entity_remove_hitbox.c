/*
** EPITECH PROJECT, 2023
** entity_remove_hitbox.c
** File description:
** entity_remove_hitbox.c
*/

#include "engine/entity_impl.h"

void entity_remove_hitbox(entity_t *entity, ssize_t id)
{
    size_t index = 0;

    for (; index < entity->hitboxes_length; index++) {
        if (entity->hitboxes[index].id == id)
            break;
    }
    if (index == entity->hitboxes_length)
        return;
    entity->hitboxes[index] = entity->hitboxes[entity->hitboxes_length - 1];
    entity->hitboxes_length--;
}
