/*
** EPITECH PROJECT, 2023
** camera_zoom.c
** File description:
** camera_zoom.c
*/

#include "utils/camera_impl.h"

void camera_zoom(camera_t *camera, float factor)
{
    if (factor > 0) {
        for (; factor > 0; factor--)
            camera->zoom *= 1.1f;
    } else {
        for (; factor < 0; factor++)
            camera->zoom /= 1.1f;
    }
    if (camera->zoom < 2.0f)
        camera->zoom = 2.0f;
    if (camera->zoom > 5.0f)
        camera->zoom = 5.0f;
    sfView_setSize(
        camera->view,
        (sfVector2f) {
            camera->size.x / camera->zoom,
            camera->size.y / camera->zoom
        }
    );
}
