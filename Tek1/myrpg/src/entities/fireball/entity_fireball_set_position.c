/*
** EPITECH PROJECT, 2023
** entity_fireball_set_position.c
** File description:
** entity_fireball_set_position.c
*/

#include "entities/fireball_impl.h"

void entity_fireball_set_position(entity_t *entity, float x, float y)
{
    entity_fireball_t *fireball = entity_get_data(entity);
    sfFloatRect *hitbox = entity_get_hitbox(entity, 0);

    sfSprite_setPosition(fireball->sprite, (sfVector2f){x + 8, y + 8});
    hitbox->left = x + 2;
    hitbox->top = y + 2;
}
