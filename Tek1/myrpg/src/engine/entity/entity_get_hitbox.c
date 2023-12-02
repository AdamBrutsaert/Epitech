/*
** EPITECH PROJECT, 2023
** entity_get_hitbox.c
** File description:
** entity_get_hitbox.c
*/

#include "engine/entity_impl.h"

#include <stdlib.h>

sfFloatRect *entity_get_hitbox(entity_t *entity, ssize_t id)
{
    for (size_t i = 0; i < entity->hitboxes_length; i++) {
        if (entity->hitboxes[i].id == id)
            return &entity->hitboxes[i].hitbox;
    }
    return NULL;
}
