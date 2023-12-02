/*
** EPITECH PROJECT, 2023
** canvas_zoom.c
** File description:
** canvas_zoom.c
*/

#include "private/paint/components/canvas.h"

void canvas_zoom(canvas_t *canvas, float factor)
{
    while (factor >= 1.0f) {
        canvas->zoom *= 1.1f;
        sfView_zoom(canvas->view, 1 / 1.1f);
        factor -= 1.0f;
    }
    while (factor <= -1.0f) {
        canvas->zoom /= 1.1f;
        sfView_zoom(canvas->view, 1.1f);
        factor += 1.0f;
    }
}
