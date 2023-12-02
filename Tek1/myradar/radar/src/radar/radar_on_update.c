/*
** EPITECH PROJECT, 2022
** radar_on_update.c
** File description:
** radar_on_update.c
*/

#include "aircraft.h"
#include "radar.h"

static void update_waiting_aircraft(radar_t *radar, float dt)
{
    aircraft_t *aircraft;

    for (uint64_t i = vector_length(radar->waiting_aircrafts); i; i--) {
        aircraft = vector_get(radar->waiting_aircrafts, i - 1);
        aircraft->delay -= dt;
        if (aircraft->delay <= 0.0f) {
            vector_push(radar->moving_aircrafts, aircraft);
            vector_set(radar->waiting_aircrafts, i - 1,
                vector_top(radar->waiting_aircrafts));
            vector_pop(radar->waiting_aircrafts);
        }
    }
}

static void update_moving_aircraft(radar_t *radar, float dt)
{
    aircraft_t *aircraft;
    vec2f_t movement;

    for (uint64_t i = vector_length(radar->moving_aircrafts); i; i--) {
        aircraft = vector_get(radar->moving_aircrafts, i - 1);
        movement = vec2f_mul(aircraft->velocity, dt);
        aircraft->center = vec2f_add(aircraft->center, movement);
        aircraft->ul = vec2f_add(aircraft->ul, movement);
        aircraft->ur = vec2f_add(aircraft->ur, movement);
        aircraft->bl = vec2f_add(aircraft->bl, movement);
        aircraft->br = vec2f_add(aircraft->br, movement);
        aircraft->flown += vec2f_length(movement);
        if (aircraft->flown >= aircraft->distance) {
            vector_set(radar->moving_aircrafts, i - 1,
                vector_top(radar->moving_aircrafts));
            vector_pop(radar->moving_aircrafts);
        }
    }
}

static void remove_hit_aircraft(radar_t *radar)
{
    aircraft_t *aircraft;

    for (uint64_t i = vector_length(radar->moving_aircrafts); i; i--) {
        aircraft = vector_get(radar->moving_aircrafts, i - 1);
        if (aircraft->hit) {
            vector_set(radar->moving_aircrafts, i - 1,
                vector_top(radar->moving_aircrafts));
            vector_pop(radar->moving_aircrafts);
        }
    }
}

static void update_fps(radar_t *radar, float dt)
{
    uint32_t seconds = 0;

    radar->elapsed += dt;
    radar->frames++;

    while (radar->elapsed >= 1.0f) {
        radar->elapsed -= 1.0f;
        seconds++;
    }
    if (seconds > 0) {
        radar->fps = (float)radar->frames / (float)seconds;
        radar->frames = 0;
    }
}

void radar_on_update(radar_t *radar, float dt)
{
    update_fps(radar, dt);
    if (radar->pause)
        return;
    radar->timer += dt;
    update_waiting_aircraft(radar, dt);
    radar_check_collisions(radar);
    remove_hit_aircraft(radar);
    update_moving_aircraft(radar, dt);
    if (vector_length(radar->moving_aircrafts) == 0 &&
        vector_length(radar->waiting_aircrafts) == 0)
        sfRenderWindow_close(radar->window);
}
