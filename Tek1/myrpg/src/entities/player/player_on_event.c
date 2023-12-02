/*
** EPITECH PROJECT, 2023
** player_on_event.c
** File description:
** player_on_event.c
*/

#include "entities/player_impl.h"

static void center_camera(player_t *player, sfEvent *event)
{
    sfVector2f position;

    if (event->type == sfEvtKeyPressed && event->key.code == sfKeySpace) {
        position = sfSprite_getPosition(player->sprite);
        camera_set_center(player->camera, (sfVector2f){
            position.x + 8, position.y + 14
        });
    }
}

static bool on_event(entity_t *entity, player_t *player, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft) {
        sfSprite_setRotation(player->weapon,
            player->direction == RIGHT ? 15 : -15);
        return player_cast_spell(entity, event);
    }
    if (event->type == sfEvtMouseButtonReleased
        && event->mouseButton.button == sfMouseLeft) {
        sfSprite_setRotation(player->weapon, 0);
    }
    return true;
}

bool player_on_event(entity_t *entity, sfEvent *event)
{
    player_t *player = entity_get_data(entity);

    center_camera(player, event);
    if (event->type == sfEvtMouseWheelScrolled)
        camera_zoom(player->camera, event->mouseWheelScroll.delta);
    if (event->type == sfEvtResized)
        camera_set_size(player->camera, (sfVector2f){event->size.width,
            event->size.height});
    if (player_is_paused(entity))
        return true;
    return on_event(entity, player, event);
}
