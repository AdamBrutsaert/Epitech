/*
** EPITECH PROJECT, 2023
** painting_on_detach.c
** File description:
** painting_on_detach.c
*/

#include "private/paint/layers/painting.h"

void painting_on_detach(__attribute__((unused)) context_t *ctx, void *data)
{
    painting_t *painting = data;

    tool_destroy(painting->tool);
    canvas_destroy(painting->canvas);
}
