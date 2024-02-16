/*
** EPITECH PROJECT, 2023
** entity_impl.h
** File description:
** entity_impl.h
*/

#pragma once

#include "entity.h"
#include "layer.h"

#define HITBOX_COLOR (sfColor_fromRGBA(255, 0, 0, 100))

typedef struct {
    sfFloatRect hitbox;
    ssize_t id;
} hitbox_t;

struct entity {
    layer_t *layer;
    void *data;
    const char *type;

    hitbox_t *hitboxes;
    size_t hitboxes_length;
    size_t hitboxes_capacity;
    size_t last_id;

    entity_on_attach_t on_attach;
    entity_on_detach_t on_detach;
    entity_on_event_t on_event;
    entity_on_update_t on_update;
    entity_on_render_t on_render;
};
