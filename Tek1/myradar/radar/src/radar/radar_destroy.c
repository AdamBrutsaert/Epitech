/*
** EPITECH PROJECT, 2022
** radar_destroy.c
** File description:
** radar_destroy.c
*/

#include "radar.h"

#include <my/memory.h>

void radar_destroy(radar_t *radar)
{
    sfCircleShape_destroy(radar->tower_range);
    sfRectangleShape_destroy(radar->aircraft_hitbox);
    sfRectangleShape_destroy(radar->grid_line);
    sfSprite_destroy(radar->aircraft_sprite);
    sfSprite_destroy(radar->bg_sprite);
    sfSprite_destroy(radar->tower_sprite);
    sfTexture_destroy(radar->tower_texture);
    sfTexture_destroy(radar->aircraft_texture);
    sfTexture_destroy(radar->bg_texture);
    sfFont_destroy(radar->font);
    sfRenderWindow_destroy(radar->window);
    vector_destroy(radar->waiting_aircrafts);
    vector_destroy(radar->moving_aircrafts);
    vector_destroy(radar->towers);
    grid_destroy(radar->grid);
    my_free(radar);
}
