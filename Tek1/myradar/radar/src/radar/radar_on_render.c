/*
** EPITECH PROJECT, 2022
** radar_on_render.c
** File description:
** radar_on_render.c
*/

#include "aircraft.h"
#include "radar.h"
#include "tower.h"

#include <math.h>

static void draw_aircrafts(radar_t *radar)
{
    aircraft_t *aircraft;
    sfRenderStates states = { .blendMode = sfBlendAlpha, .shader = NULL,
        .texture = NULL};

    for (uint64_t i = 0; i < vector_length(radar->moving_aircrafts); i++) {
        aircraft = vector_get(radar->moving_aircrafts, i);
        states.transform = sfTransform_Identity;
        sfTransform_translate(&states.transform,
            aircraft->center.x,
            aircraft->center.y);
        sfTransform_rotate(&states.transform,
            aircraft->angle * 180.0f / 3.1415926535897932384f);
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window, radar->aircraft_sprite,
                &states);
        if (radar->show_hitboxes)
            sfRenderWindow_drawRectangleShape(radar->window,
                radar->aircraft_hitbox, &states);
    }
}

static void draw_towers(radar_t *radar)
{
    tower_t *tower;

    for (uint64_t i = 0; i < vector_length(radar->towers); i++) {
        tower = vector_get(radar->towers, i);
        sfSprite_setPosition(radar->tower_sprite, (sfVector2f) {
            tower->position.x - TOWER_WIDTH / 2.0f,
            tower->position.y - TOWER_HEIGHT / 2.0f,
        });
        sfCircleShape_setPosition(radar->tower_range, (sfVector2f) {
            tower->position.x - tower->range,
            tower->position.y - tower->range,
        });
        sfCircleShape_setRadius(radar->tower_range, tower->range);
        if (radar->show_sprites)
            sfRenderWindow_drawSprite(radar->window, radar->tower_sprite, NULL);
        if (radar->show_hitboxes)
            sfRenderWindow_drawCircleShape(radar->window, radar->tower_range,
                NULL);
    }
}

static void draw_grid(radar_t *radar)
{
    if (!radar->show_grid)
        return;
    for (uint32_t i = 1; i < radar->grid->precision; i++) {
        sfRectangleShape_setPosition(radar->grid_line, (sfVector2f) {
            0, i * (1080.0f / radar->grid->precision)});
        sfRectangleShape_setSize(radar->grid_line, (sfVector2f) {
            1920.0f, 2.0f});
        sfRenderWindow_drawRectangleShape(radar->window, radar->grid_line,
            NULL);
    }
    for (uint32_t i = 1; i < radar->grid->precision; i++) {
        sfRectangleShape_setPosition(radar->grid_line, (sfVector2f) {
            i * (1920.0f / radar->grid->precision), 0});
        sfRectangleShape_setSize(radar->grid_line, (sfVector2f) {
            2.0f, 1080.0f});
        sfRenderWindow_drawRectangleShape(radar->window, radar->grid_line,
            NULL);
    }
}

void radar_on_render(radar_t *radar)
{
    sfRenderWindow_drawSprite(radar->window, radar->bg_sprite, NULL);
    draw_towers(radar);
    draw_aircrafts(radar);
    draw_grid(radar);
    if (radar->show_debug)
        radar_show_debug(radar);
}
