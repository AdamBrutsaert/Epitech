/*
** EPITECH PROJECT, 2023
** canvas_get_view.c
** File description:
** canvas_get_view.c
*/

#include "private/paint/components/canvas.h"

sfView *canvas_get_view(canvas_t *canvas)
{
    return canvas->view;
}
