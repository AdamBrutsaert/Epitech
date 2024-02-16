/*
** EPITECH PROJECT, 2022
** image_update_vertices.c
** File description:
** image_update_vertices.c
*/

#include "hunter.h"

static void image_update_vertex0(image_data_t *data)
{
    sfVertex *vertex = sfVertexArray_getVertex(data->vertices, 0);
    vertex->position.x = data->position.x;
    vertex->position.y = data->position.y;
    vertex->texCoords.x = data->texture_rect.left;
    vertex->texCoords.y = data->texture_rect.top;
}

static void image_update_vertex1(image_data_t *data)
{
    sfVertex *vertex = sfVertexArray_getVertex(data->vertices, 1);
    vertex->position.x = data->position.x + data->texture_rect.width;
    vertex->position.y = data->position.y;
    vertex->texCoords.x = data->texture_rect.left + data->texture_rect.width;
    vertex->texCoords.y = data->texture_rect.top;
}

static void image_update_vertex2(image_data_t *data)
{
    sfVertex *vertex = sfVertexArray_getVertex(data->vertices, 2);
    vertex->position.x = data->position.x + data->texture_rect.width;
    vertex->position.y = data->position.y + data->texture_rect.height;
    vertex->texCoords.x = data->texture_rect.left + data->texture_rect.width;
    vertex->texCoords.y = data->texture_rect.top + data->texture_rect.height;
}

static void image_update_vertex3(image_data_t *data)
{
    sfVertex *vertex = sfVertexArray_getVertex(data->vertices, 3);
    vertex->position.x = data->position.x;
    vertex->position.y = data->position.y + data->texture_rect.height;
    vertex->texCoords.x = data->texture_rect.left;
    vertex->texCoords.y = data->texture_rect.top + data->texture_rect.height;
}

void image_update_vertices(scene_t *scene)
{
    image_data_t *data = scene->data;

    image_update_vertex0(data);
    image_update_vertex1(data);
    image_update_vertex2(data);
    image_update_vertex3(data);
}
