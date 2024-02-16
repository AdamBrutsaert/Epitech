/*
** EPITECH PROJECT, 2023
** layer_destroy.c
** File description:
** layer_destroy.c
*/

#include "private/engine/layer.h"
#include "my/memory.h"

void layer_destroy(layer_t *layer)
{
    if (!layer)
        return;
    my_free(layer->data);
    my_free(layer);
}
