/*
** EPITECH PROJECT, 2023
** entity_is_colliding.c
** File description:
** entity_is_colliding.c
*/

#include "engine/entity_impl.h"

static bool is_colliding(entity_t *entity, sfFloatRect *hitbox)
{
    for (size_t i = 0; i < entity->hitboxes_length; i++) {
        if (sfFloatRect_intersects(hitbox, &entity->hitboxes[i].hitbox, NULL))
            return true;
    }
    return false;
}

bool entity_is_colliding(entity_t *entity, entity_t *other)
{
    for (size_t i = 0; i < entity->hitboxes_length; i++) {
        if (is_colliding(other, &entity->hitboxes[i].hitbox))
            return true;
    }
    return false;
}
