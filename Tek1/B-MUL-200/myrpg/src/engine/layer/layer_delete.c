/*
** EPITECH PROJECT, 2023
** layer_delete.c
** File description:
** layer_delete.c
*/

#include "engine/layer_impl.h"

#include <stdlib.h>

void layer_delete(layer_t *layer)
{
    if (layer == NULL)
        return;
    for (size_t i = layer->entities_length; i > 0; i--)
        layer_remove_entity(layer, layer->entities[i - 1]);
    sfView_destroy(layer->view);
    free(layer->entities);
    free(layer->data);
    free(layer);
}
