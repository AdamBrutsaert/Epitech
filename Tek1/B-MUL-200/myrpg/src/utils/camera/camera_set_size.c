/*
** EPITECH PROJECT, 2023
** camera_set_size.c
** File description:
** camera_set_size.c
*/

#include "utils/camera_impl.h"

void camera_set_size(camera_t *camera, sfVector2f size)
{
    camera->size = size;
    sfView_setSize(
        camera->view,
        (sfVector2f) { size.x / camera->zoom, size.y / camera->zoom}
    );
}
