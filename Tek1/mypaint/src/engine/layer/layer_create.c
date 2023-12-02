/*
** EPITECH PROJECT, 2023
** layer_create.c
** File description:
** layer_create.c
*/

#include "private/engine/layer.h"
#include "my/memory.h"

layer_t *layer_create(size_t data_size)
{
    layer_t *layer = my_calloc(sizeof(layer_t));

    if (!layer)
        return NULL;
    layer->data = my_calloc(data_size);
    if (!layer->data && data_size) {
        my_free(layer);
        return NULL;
    }
    return layer;
}
