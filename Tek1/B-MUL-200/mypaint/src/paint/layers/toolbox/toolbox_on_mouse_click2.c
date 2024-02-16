/*
** EPITECH PROJECT, 2023
** toolbox_on_mouse_click2.c
** File description:
** toolbox_on_mouse_click2.c
*/

#include "private/paint/layers/toolbox.h"
#include "paint/components/tools/pencil.h"
#include "paint/components/tools/eraser.h"

static bool for_pencil(toolbox_t *toolbox, sfEvent *event)
{
    if (pencil_is_rect(tool_get(toolbox->tool))) {
        if (button_contains(toolbox->circle, event->mouseButton.x,
            event->mouseButton.y)) {
            pencil_set_rect(tool_get(toolbox->tool), false);
            toolbox_reset_button(toolbox->rect);
            return true;
        }
    }
    if (!pencil_is_rect(tool_get(toolbox->tool))) {
        if (button_contains(toolbox->rect, event->mouseButton.x,
            event->mouseButton.y)) {
            pencil_set_rect(tool_get(toolbox->tool), true);
            toolbox_reset_button(toolbox->circle);
            return true;
        }
    }
    return false;
}

static bool for_eraser(toolbox_t *toolbox, sfEvent *event)
{
    if (eraser_is_rect(tool_get(toolbox->tool))) {
        if (button_contains(toolbox->circle, event->mouseButton.x,
            event->mouseButton.y)) {
            eraser_set_rect(tool_get(toolbox->tool), false);
            toolbox_reset_button(toolbox->rect);
            return true;
        }
    }
    if (!eraser_is_rect(tool_get(toolbox->tool))) {
        if (button_contains(toolbox->rect, event->mouseButton.x,
            event->mouseButton.y)) {
            eraser_set_rect(tool_get(toolbox->tool), true);
            toolbox_reset_button(toolbox->circle);
            return true;
        }
    }
    return false;
}

bool toolbox_on_mouse_click2(toolbox_t *toolbox, sfEvent *event)
{
    if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_PENCIL
        && for_pencil(toolbox, event))
        return true;
    if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_ERASER
        && for_eraser(toolbox, event))
        return true;
    return false;
}
