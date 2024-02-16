/*
** EPITECH PROJECT, 2023
** layer.h
** File description:
** layer.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <stdbool.h>

typedef struct layer layer_t;
struct context;

typedef bool (*on_attach_t)(struct context *, void *);
typedef void (*on_detach_t)(struct context *, void *);
typedef bool (*on_event_t)(struct context *, void *, sfEvent *event);
typedef bool (*on_update_t)(struct context *, void *, float dt);
typedef bool (*on_render_t)(struct context *, void *);

layer_t *layer_create(size_t data_size);
void layer_destroy(layer_t *layer);

void layer_bind_on_attach(layer_t *layer, on_attach_t handler);
void layer_bind_on_detach(layer_t *layer, on_detach_t handler);
void layer_bind_on_event(layer_t *layer, on_event_t handler);
void layer_bind_on_update(layer_t *layer, on_update_t handler);
void layer_bind_on_render(layer_t *layer, on_render_t handler);

void *layer_get_data(layer_t *layer);
