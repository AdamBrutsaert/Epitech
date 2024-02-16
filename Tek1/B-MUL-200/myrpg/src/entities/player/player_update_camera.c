/*
** EPITECH PROJECT, 2023
** player_update_camera.c
** File description:
** player_update_camera.c
*/

#include "entities/player_impl.h"

void player_update_camera(entity_t *entity, float dx, float dy, float dt)
{
    player_t *player = entity_get_data(entity);
    sfVector2f pos = sfSprite_getPosition(player->sprite);
    sfVector2f center;

    if (dx != 0 || dy != 0)
        camera_set_center(player->camera, (sfVector2f){pos.x + 8, pos.y + 14});
    center = camera_get_center(player->camera);
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        center.x -= CAMERA_SPEED * dt;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        center.x += CAMERA_SPEED * dt;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        center.y -= CAMERA_SPEED * dt;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        center.y += CAMERA_SPEED * dt;
    camera_set_center(player->camera, center);
    camera_update(player->camera, dt);
}
