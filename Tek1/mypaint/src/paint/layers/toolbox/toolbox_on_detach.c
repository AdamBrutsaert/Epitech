/*
** EPITECH PROJECT, 2023
** toolbox_on_detach.c
** File description:
** toolbox_on_detach.c
*/

#include "private/paint/layers/toolbox.h"

void toolbox_on_detach(__attribute__((unused)) context_t *ctx, void *data)
{
    toolbox_t *toolbox = data;

    sfFont_destroy(toolbox->font);
    sfRectangleShape_destroy(toolbox->rect_shape);
    sfCircleShape_destroy(toolbox->circle_shape);
    button_destroy(toolbox->grow);
    button_destroy(toolbox->shrink);
    button_destroy(toolbox->rect);
    button_destroy(toolbox->circle);
}
