/*
** EPITECH PROJECT, 2022
** scene.h
** File description:
** scene.h
*/

#pragma once

#include "types.h"
#include <SFML/Graphics.h>

typedef struct {
    scene_t **scenes;
    uint32_t length;
    uint32_t capacity;
} scene_vector_t;

typedef struct {
    void (*on_attach)(scene_t *scene);
    void (*on_detach)(scene_t *scene);
    void (*on_event)(scene_t *scene, sfEvent *event);
    void (*on_signal)(scene_t *scene, scene_t *sender, char const *name);
    void (*on_update)(scene_t *scene, float dt);
    void (*on_render)(scene_t *scene);
} scene_handlers_t;

struct scene {
    scene_handlers_t handlers;
    scene_vector_t children;
    app_t *app;
    void *args;
    void *data;
};

scene_t *scene_create(app_t *app, void *args, uint32_t data_size);
void scene_destroy(scene_t *scene);

void scene_bind(scene_t *scene, char const *name, void (*func)(void));
void scene_on_attach(scene_t *scene);
void scene_on_detach(scene_t *scene);
void scene_on_event(scene_t *scene, sfEvent *event);
void scene_on_signal(scene_t *scene, scene_t *sender, char const *name);
void scene_on_update(scene_t *scene, float dt);
void scene_on_render(scene_t *scene);

scene_t *scene_add_child(scene_t *scene, scene_t *child);
void scene_remove_child(scene_t *scene, scene_t *child);

void scene_send_signal(scene_t *scene, char const *name);
