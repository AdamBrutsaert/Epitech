/*
** EPITECH PROJECT, 2023
** entity_add_hitbox.c
** File description:
** entity_add_hitbox.c
*/

#include "engine/entity_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(entity_t *entity)
{
    size_t capacity = entity->hitboxes_capacity * 2
        + !entity->hitboxes_capacity;
    hitbox_t *hitboxes = malloc(capacity * sizeof(hitbox_t));

    if (hitboxes == NULL)
        return false;
    my_memcpy(
        hitboxes,
        entity->hitboxes,
        entity->hitboxes_length * sizeof(hitbox_t)
    );
    free(entity->hitboxes);
    entity->hitboxes = hitboxes;
    entity->hitboxes_capacity = capacity;
    return true;
}

ssize_t entity_add_hitbox(entity_t *entity, sfFloatRect hitbox)
{
    if (entity->hitboxes_length == entity->hitboxes_capacity
        && !grow(entity))
        return -1;
    entity->hitboxes[entity->hitboxes_length] = (hitbox_t) {
        .id = entity->last_id,
        .hitbox = hitbox,
    };
    entity->last_id++;
    entity->hitboxes_length++;
    return entity->last_id - 1;
}
