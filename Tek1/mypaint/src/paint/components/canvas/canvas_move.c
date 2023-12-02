/*
** EPITECH PROJECT, 2023
** canvas_move.c
** File description:
** canvas_move.c
*/

#include "private/paint/components/canvas.h"

void canvas_move(canvas_t *canvas, sfVector2f offset)
{
    canvas->center.x += offset.x / canvas->zoom;
    canvas->center.y += offset.y / canvas->zoom;
    sfView_setCenter(canvas->view, canvas->center);
}
