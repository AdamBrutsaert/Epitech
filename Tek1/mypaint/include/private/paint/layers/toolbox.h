/*
** EPITECH PROJECT, 2023
** toolbox.h
** File description:
** toolbox.h
*/

#pragma once

#include "paint/layers/toolbox.h"
#include "paint/components/button.h"

typedef struct {
    tool_t *tool;
    sfFont *font;

    button_t *grow;
    button_t *shrink;

    button_t *rect;
    button_t *circle;
    sfRectangleShape *rect_shape;
    sfCircleShape *circle_shape;
} toolbox_t;

void toolbox_reset_button(button_t *button);

void toolbox_on_mouse_move(toolbox_t *toolbox, sfEvent *event);
bool toolbox_on_mouse_click(toolbox_t *toolbox, sfEvent *event);
bool toolbox_on_mouse_click2(toolbox_t *toolbox, sfEvent *event);
