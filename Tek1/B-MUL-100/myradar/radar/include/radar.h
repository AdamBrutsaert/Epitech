/*
** EPITECH PROJECT, 2022
** radar.h
** File description:
** radar.h
*/

#pragma once

#include "aircraft.h"
#include "tower.h"
#include "grid.h"

#include <SFML/Graphics.h>
#include <my/vector.h>
#include <stdint.h>

typedef struct {
    sfRenderWindow *window;

    vector_t *waiting_aircrafts;
    vector_t *moving_aircrafts;
    sfTexture *aircraft_texture;
    sfSprite *aircraft_sprite;
    sfRectangleShape *aircraft_hitbox;

    vector_t *towers;
    sfTexture *tower_texture;
    sfSprite *tower_sprite;
    sfCircleShape *tower_range;

    grid_t *grid;
    sfRectangleShape *grid_line;

    sfTexture *bg_texture;
    sfSprite *bg_sprite;

    int8_t fullscreen;
    int8_t pause;
    int8_t cap_fps;
    int8_t show_sprites;
    int8_t show_hitboxes;
    int8_t show_grid;
    int8_t show_debug;

    sfFont *font;
    float timer;
    float frames;
    float elapsed;
    float fps;
} radar_t;

int32_t exec_radar(int argc, char **argv);

radar_t *radar_create(vector_t *aircrafts, vector_t *towers);
void radar_destroy(radar_t *radar);

void radar_run(radar_t *radar);

void radar_on_event(radar_t *radar, sfEvent *event);
void radar_on_update(radar_t *radar, float dt);
void radar_on_render(radar_t *radar);

int8_t radar_check_resources(void);
void radar_update_view(radar_t *radar);
void radar_check_collisions(radar_t *radar);
void radar_show_debug(radar_t *radar);
