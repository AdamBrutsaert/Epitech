/*
** EPITECH PROJECT, 2023
** player_update_state.c
** File description:
** player_update_state.c
*/

#include "entities/player_impl.h"

void set_state(
    player_t *player,
    player_state_t state,
    player_direction_t direction
)
{
    if (player->state != state) {
        animation_reset(player->idle_animation);
        animation_reset(player->walk_animation);
    }
    if (player->direction != direction
        && sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSprite_setRotation(player->weapon,
            direction == RIGHT ? 15 : -15);
    }
    player->state = state;
    player->direction = direction;
}

void player_update_state(entity_t *entity, float dx, float dy)
{
    player_t *player = entity_get_data(entity);

    if (dx == 0 && dy == 0)
        set_state(player, IDLE, player->direction);
    if (dx > 0)
        set_state(player, WALK, RIGHT);
    if (dx < 0)
        set_state(player, WALK, LEFT);
    if (dx == 0 && dy != 0)
        set_state(player, WALK, player->direction);
}
