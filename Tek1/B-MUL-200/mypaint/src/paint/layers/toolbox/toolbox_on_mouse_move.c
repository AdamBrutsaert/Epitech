/*
** EPITECH PROJECT, 2023
** toolbox_on_mouse_move.c
** File description:
** toolbox_on_mouse_move.c
*/

#include "private/paint/layers/toolbox.h"
#include "paint/components/tools/pencil.h"
#include "paint/components/tools/eraser.h"

void set(button_t *button)
{
    button_set_color(button, sfColor_fromRGB(24, 50, 75));
    button_set_outline_color(button, sfTransparent);
    button_set_text_color(button, sfWhite);
}

void set_if_hovered(button_t *button, float x, float y)
{
    if (button_contains(button, x, y)) {
        set(button);
    } else {
        toolbox_reset_button(button);
    }
}

static void set_for_pencil(toolbox_t *toolbox, sfEvent *event)
{
    if (pencil_is_rect(tool_get(toolbox->tool)))
        set_if_hovered(toolbox->circle, event->mouseMove.x, event->mouseMove.y);
    if (!pencil_is_rect(tool_get(toolbox->tool)))
        set_if_hovered(toolbox->rect, event->mouseMove.x, event->mouseMove.y);
}

static void set_for_eraser(toolbox_t *toolbox, sfEvent *event)
{
    if (eraser_is_rect(tool_get(toolbox->tool)))
        set_if_hovered(toolbox->circle, event->mouseMove.x, event->mouseMove.y);
    if (!eraser_is_rect(tool_get(toolbox->tool)))
        set_if_hovered(toolbox->rect, event->mouseMove.x, event->mouseMove.y);
}

void toolbox_on_mouse_move(toolbox_t *toolbox, sfEvent *event)
{
    set_if_hovered(toolbox->grow, event->mouseMove.x, event->mouseMove.y);
    set_if_hovered(toolbox->shrink, event->mouseMove.x, event->mouseMove.y);
    if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_PENCIL)
        set_for_pencil(toolbox, event);
    if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_ERASER)
        set_for_eraser(toolbox, event);
}
