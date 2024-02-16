/*
** EPITECH PROJECT, 2023
** painting_get_canvas.c
** File description:
** painting_get_canvas.c
*/

#include "private/paint/layers/painting.h"

canvas_t *painting_get_canvas(layer_t *layer)
{
    painting_t *painting = layer_get_data(layer);

    return painting->canvas;
}
