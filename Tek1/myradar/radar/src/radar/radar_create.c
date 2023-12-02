/*
** EPITECH PROJECT, 2022
** radar_create.c
** File description:
** radar_create.c
*/

#include "aircraft.h"
#include "radar.h"

#include <my/memory.h>
#include <math.h>

static uint32_t get_precision(radar_t *radar)
{
    uint32_t precision = sqrtf(vector_length(radar->waiting_aircrafts) / 2.0f);

    if (precision < 10)
        precision = 10;
    if (precision > 50)
        precision = 50;
    return precision;
}

static void init_aircrafts(radar_t *radar, vector_t *aircrafts)
{
    radar->waiting_aircrafts = aircrafts;
    radar->moving_aircrafts = vector_create(sizeof(aircraft_t));
    vector_reserve(radar->moving_aircrafts, vector_length(aircrafts));
    radar->aircraft_texture = sfTexture_createFromFile("res/aircraft.png",
        NULL);
    radar->aircraft_sprite = sfSprite_create();
    sfSprite_setTexture(radar->aircraft_sprite, radar->aircraft_texture,
        sfTrue);
    sfSprite_setPosition(radar->aircraft_sprite,
        (sfVector2f){-AIRCRAFT_SIZE / 2.0f, -AIRCRAFT_SIZE / 2.0f});
    radar->aircraft_hitbox = sfRectangleShape_create();
    sfRectangleShape_setOutlineThickness(radar->aircraft_hitbox, 2.0f);
    sfRectangleShape_setOutlineColor(radar->aircraft_hitbox,
        sfColor_fromRGB(52, 152, 219));
    sfRectangleShape_setFillColor(radar->aircraft_hitbox, sfTransparent);
    sfRectangleShape_setSize(radar->aircraft_hitbox, (sfVector2f){AIRCRAFT_SIZE,
        AIRCRAFT_SIZE});
    sfRectangleShape_setPosition(radar->aircraft_hitbox,
        (sfVector2f){-AIRCRAFT_SIZE / 2.0f, -AIRCRAFT_SIZE / 2.0f});
}

static void init_towers(radar_t *radar, vector_t *towers)
{
    radar->towers = towers;
    radar->tower_texture = sfTexture_createFromFile("res/tower.png", NULL);
    radar->tower_sprite = sfSprite_create();
    sfSprite_setTexture(radar->tower_sprite, radar->tower_texture, sfTrue);
    radar->tower_range = sfCircleShape_create();
    sfCircleShape_setFillColor(radar->tower_range, sfTransparent);
    sfCircleShape_setOutlineColor(radar->tower_range,
        sfColor_fromRGB(46, 204, 113));
    sfCircleShape_setOutlineThickness(radar->tower_range, 4.0f);
}

static void init_miscellaneous(radar_t *radar)
{
    radar->grid = grid_create(get_precision(radar));
    radar->grid_line = sfRectangleShape_create();
    sfRectangleShape_setFillColor(radar->grid_line,
        sfColor_fromRGBA(0, 0, 0, 128));
    radar->bg_texture = sfTexture_createFromFile("res/planisphere.jpg", NULL);
    radar->bg_sprite = sfSprite_create();
    sfSprite_setTexture(radar->bg_sprite, radar->bg_texture, sfTrue);
    radar->show_sprites = 1;
    radar->show_hitboxes = 0;
    radar->show_grid = 0;
    radar->show_debug = 1;
    radar->cap_fps = 1;
    radar->fullscreen = 1;
    radar->pause = 0;
    radar->font = sfFont_createFromFile("res/font.ttf");
    radar->timer = 0;
    radar->frames = 0;
    radar->elapsed = 0;
    radar->fps = 0;
}

radar_t *radar_create(vector_t *aircrafts, vector_t *towers)
{
    radar_t *radar = my_malloc(sizeof(radar_t));

    radar->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
        "Radar", sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(radar->window, 60);
    radar_update_view(radar);
    init_aircrafts(radar, aircrafts);
    init_towers(radar, towers);
    init_miscellaneous(radar);
    return radar;
}
