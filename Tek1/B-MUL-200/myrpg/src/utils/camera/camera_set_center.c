/*
** EPITECH PROJECT, 2023
** camera_set_center.c
** File description:
** camera_set_center.c
*/

#include "utils/camera_impl.h"

void camera_set_center(camera_t *camera, sfVector2f center)
{
    sfVector2f position = sfView_getCenter(camera->view);
    float dx = center.x - camera->previous_center.x;
    float dy = center.y - camera->previous_center.y;

    if (dx == camera->target_delta.x && dy == camera->target_delta.y)
        return;
    camera->previous_center = position;
    camera->target_delta.x = center.x - position.x;
    camera->target_delta.y = center.y - position.y;
    camera->interpolation = 0.0f;
}
