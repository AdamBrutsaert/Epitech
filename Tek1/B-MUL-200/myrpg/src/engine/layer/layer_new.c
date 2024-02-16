/*
** EPITECH PROJECT, 2023
** layer_new.c
** File description:
** layer_new.c
*/

#include "engine/layer_impl.h"
#include "my/memory.h"

layer_t *layer_new(size_t data_size)
{
    layer_t *layer = my_calloc(sizeof(layer_t));

    if (layer == NULL)
        return (NULL);
    layer->data = my_calloc(data_size);
    if (layer->data == NULL && data_size != 0) {
        layer_delete(layer);
        return NULL;
    }
    layer->view = sfView_create();
    if (layer->view == NULL) {
        layer_delete(layer);
        return NULL;
    }
    return layer;
}
