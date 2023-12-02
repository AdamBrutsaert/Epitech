/*
** EPITECH PROJECT, 2022
** image_on_attach.c
** File description:
** image_on_attach.c
*/

#include "hunter.h"
#include "my.h"

void image_on_attach(scene_t *scene)
{
    image_args_t *args = scene->args;
    image_data_t *data = scene->data;

    data->states.blendMode = sfBlendAlpha;
    my_memcpy(&data->states.blendMode, &sfBlendAlpha, sizeof(sfBlendMode));
    data->states.shader = NULL;
    data->states.texture = args->texture;
    my_memcpy(&data->states.transform, &sfTransform_Identity,
        sizeof(sfTransform));
    data->position = args->position;
    data->texture_rect = args->texture_rect;
    data->vertices = sfVertexArray_create();
    sfVertexArray_setPrimitiveType(data->vertices, sfQuads);
    sfVertexArray_resize(data->vertices, 4);
    image_update_vertices(scene);
    scene_send_signal(scene, "image_created");
}
