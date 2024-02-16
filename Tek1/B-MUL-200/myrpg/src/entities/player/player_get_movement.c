/*
** EPITECH PROJECT, 2023
** player_get_movement.c
** File description:
** player_get_movement.c
*/

#include "entities/player_impl.h"

#include <math.h>

void player_get_movement(entity_t *entity, float *dx, float *dy)
{
    float length;

    *dx = 0;
    *dy = 0;
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        *dx -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyD))
        *dx += 1;
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        *dy -= 1;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        *dy += 1;
    if (*dx != 0 || *dy != 0) {
        length = sqrtf(*dx * *dx + *dy * *dy);
        *dx = *dx / length * PLAYER_SPEED;
        *dy = *dy / length * PLAYER_SPEED;
    }
}
