/*
** EPITECH PROJECT, 2023
** camera_get_center.c
** File description:
** camera_get_center.c
*/

#include "utils/camera_impl.h"

sfVector2f camera_get_center(camera_t *camera)
{
    sfVector2f target_center = camera->previous_center;

    target_center.x += camera->target_delta.x;
    target_center.y += camera->target_delta.y;
    return target_center;
}
