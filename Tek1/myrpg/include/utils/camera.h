/*
** EPITECH PROJECT, 2023
** camera.h
** File description:
** camera.h
*/

#pragma once

#include <SFML/Graphics.h>

typedef struct camera camera_t;

camera_t *camera_new(void);
void camera_delete(camera_t *camera);

void camera_teleport(camera_t *camera, sfVector2f center);
void camera_set_center(camera_t *camera, sfVector2f center);
void camera_set_size(camera_t *camera, sfVector2f size);
void camera_zoom(camera_t *camera, float factor);
void camera_update(camera_t *camera, float dt);
sfView *camera_get_view(camera_t *camera);
sfVector2f camera_get_center(camera_t *camera);
