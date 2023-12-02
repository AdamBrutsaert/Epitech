/*
** EPITECH PROJECT, 2023
** entity_fireball_set_movement.c
** File description:
** entity_fireball_set_movement.c
*/

#include "entities/fireball_impl.h"

#include <math.h>

void entity_fireball_set_movement(entity_t *entity, float dx, float dy)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    float angle = acos(dx / sqrt(dx * dx + dy * dy)) * 180 / 3.1415926535;

    fireball->movement.x = dx;
    fireball->movement.y = dy;
    if (dy < 0)
        angle = -angle;
    sfSprite_setRotation(fireball->sprite, angle);
}
