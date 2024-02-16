/*
** EPITECH PROJECT, 2023
** layer_get_view.c
** File description:
** layer_get_view.c
*/

#include "engine/layer_impl.h"

sfView *layer_get_view(layer_t *layer)
{
    return layer->view;
}
