/*
** EPITECH PROJECT, 2023
** camera_new.c
** File description:
** camera_new.c
*/

#include "utils/camera_impl.h"
#include "my/memory.h"

camera_t *camera_new(void)
{
    camera_t *camera = my_calloc(sizeof(camera_t));

    if (camera == NULL)
        return NULL;
    camera->view = sfView_create();
    if (camera->view == NULL) {
        camera_delete(camera);
        return NULL;
    }
    camera->size = (sfVector2f) {0, 0};
    camera->zoom = 2;
    return camera;
}
