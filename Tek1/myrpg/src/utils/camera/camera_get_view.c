/*
** EPITECH PROJECT, 2023
** camera_get_view.c
** File description:
** camera_get_view.c
*/

#include "utils/camera_impl.h"

sfView *camera_get_view(camera_t *camera)
{
    return camera->view;
}
