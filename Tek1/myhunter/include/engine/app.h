/*
** EPITECH PROJECT, 2022
** app.h
** File description:
** app.h
*/

#pragma once

#include "scene.h"
#include <SFML/Graphics.h>
#include <stdint.h>

typedef struct {
    char const *name;
    scene_t *sender;
} signal_t;

typedef struct {
    signal_t *signals;
    uint32_t length;
    uint32_t capacity;
} signal_queue_t;

struct app {
    sfRenderWindow *window;
    scene_t *scene;
    scene_t *next_scene;
    signal_queue_t signal_queue;
};

app_t *app_create(uint32_t width, uint32_t height,
    char const *title);
void app_destroy(app_t *app);

void app_set_scene(app_t *app, scene_t *scene);
void app_run(app_t *app);
