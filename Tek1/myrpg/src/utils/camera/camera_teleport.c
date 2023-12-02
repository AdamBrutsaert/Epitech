/*
** EPITECH PROJECT, 2023
** camera_teleport.c
** File description:
** camera_teleport.c
*/

#include "utils/camera_impl.h"

void camera_teleport(camera_t *camera, sfVector2f center)
{
    camera->target_delta = (sfVector2f) {0, 0};
    camera->interpolation = 1.0f;
    camera->previous_center = center;
    sfView_setCenter(camera->view, center);
}
