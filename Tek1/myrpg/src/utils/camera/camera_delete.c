/*
** EPITECH PROJECT, 2023
** camera_delete.c
** File description:
** camera_delete.c
*/

#include "utils/camera_impl.h"

#include <stdlib.h>

void camera_delete(camera_t *camera)
{
    if (camera == NULL)
        return;
    sfView_destroy(camera->view);
    free(camera);
}
