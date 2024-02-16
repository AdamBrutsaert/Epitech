/*
** EPITECH PROJECT, 2023
** player_cast_spell.c
** File description:
** player_cast_spell.c
*/

#include "entities/player_impl.h"
#include "entities/fireball.h"

#include <math.h>

static sfVector2f get_movement(entity_t *entity, sfVector2f pos, sfEvent *event)
{
    player_t *player = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(
        window,
        (sfVector2i){event->mouseButton.x, event->mouseButton.y},
        camera_get_view(player->camera)
    );
    sfVector2f movement = {mouse.x - pos.x - 8, mouse.y - pos.y - 8};
    float length;

    if (movement.x != 0 || movement.y != 0) {
        length = sqrtf(movement.x * movement.x + movement.y * movement.y);
        movement.x /= length;
        movement.y /= length;
    }
    return movement;
}

static sfVector2f get_position(entity_t *entity)
{
    player_t *player = entity_get_data(entity);
    sfVector2f position = sfSprite_getPosition(player->sprite);

    if (player->direction == LEFT) {
        position.x -= 16;
    } else {
        position.x += 16;
    }
    return position;
}

static bool cast(entity_t *entity, sfEvent *event)
{
    layer_t *layer = entity_get_layer(entity);
    entity_t *fireball = entity_fireball_new(entity);
    sfVector2f position = get_position(entity);
    sfVector2f movement = get_movement(entity, position, event);

    if (fireball == NULL || !layer_add_entity(layer, fireball))
        return false;
    entity_fireball_set_position(fireball, position.x, position.y);
    entity_fireball_set_movement(fireball, movement.x, movement.y);
    return true;
}

bool player_cast_spell(entity_t *entity, sfEvent *event)
{
    player_t *player = entity_get_data(entity);

    if (player->cooldown <= 0) {
        player->cooldown = player_get_cooldown(entity);
        return cast(entity, event);
    }
    return true;
}
