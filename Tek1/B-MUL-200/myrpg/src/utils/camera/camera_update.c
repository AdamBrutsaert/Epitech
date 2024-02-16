/*
** EPITECH PROJECT, 2023
** camera_update.c
** File description:
** camera_update.c
*/

#include "utils/camera_impl.h"
#include "utils/interpolation.h"

void camera_update(camera_t *camera, float dt)
{
    camera->interpolation += SMOOTH_ACCELERATION * dt;
    if (camera->interpolation > 1.0f)
        camera->interpolation = 1.0f;
    sfView_setCenter(camera->view, (sfVector2f) {
        camera->previous_center.x
            + camera->target_delta.x
                * interpolation_ease_out_quad(camera->interpolation),
        camera->previous_center.y
            + camera->target_delta.y
                * interpolation_ease_out_quad(camera->interpolation)
    });
}
