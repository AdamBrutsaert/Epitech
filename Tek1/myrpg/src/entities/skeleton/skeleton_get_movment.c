/*
** EPITECH PROJECT, 2023
** MyRPG
** File description:
** skeleton_get_movment
*/

#include "entities/skeleton_impl.h"
#include <math.h>

void skeleton_get_movement(entity_t *entity, float *dx, float *dy)
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
        *dx = *dx / length * SKELETON_SPEED;
        *dy = *dy / length * SKELETON_SPEED;
    }
}
