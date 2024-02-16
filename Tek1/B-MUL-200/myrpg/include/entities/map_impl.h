/*
** EPITECH PROJECT, 2023
** map_impl.h
** File description:
** map_impl.h
*/

#pragma once

#include "map.h"

typedef struct {
    const char *map;
    const char *collisions;
    sfSprite *sprite;
    sfTexture *texture;
} entity_map_t;

bool entity_map_on_attach(entity_t *entity);
void entity_map_on_detach(entity_t *entity);
bool entity_map_on_event(entity_t *entity, sfEvent *event);
bool entity_map_on_update(entity_t *entity, float dt);
void entity_map_on_render(entity_t *entity);

bool entity_map_parse_collisions(entity_t *entity);
