/*
** EPITECH PROJECT, 2023
** toolbox_on_mouse_click.c
** File description:
** toolbox_on_mouse_click.c
*/

#include "private/paint/layers/toolbox.h"
#include "paint/components/tools/pencil.h"
#include "paint/components/tools/eraser.h"

static float max(float a, float b)
{
    return a > b ? a : b;
}

static bool on_grow(toolbox_t *toolbox, sfEvent *event)
{
    float size;

    if (button_contains(toolbox->grow, event->mouseButton.x,
        event->mouseButton.y)) {
        if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_PENCIL) {
            size = pencil_get_thickness(tool_get(toolbox->tool));
            pencil_set_thickness(tool_get(toolbox->tool), size + 1);
        }
        if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_ERASER) {
            size = eraser_get_thickness(tool_get(toolbox->tool));
            eraser_set_thickness(tool_get(toolbox->tool), size + 1);
        }
        return true;
    }
    return false;
}

static bool on_shrink(toolbox_t *toolbox, sfEvent *event)
{
    float size;

    if (button_contains(toolbox->shrink, event->mouseButton.x,
        event->mouseButton.y)) {
        if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_PENCIL) {
            size = pencil_get_thickness(tool_get(toolbox->tool));
            pencil_set_thickness(tool_get(toolbox->tool), max(size - 1, 1));
        }
        if (toolbox->tool && tool_get_type(toolbox->tool) == TOOL_ERASER) {
            size = eraser_get_thickness(tool_get(toolbox->tool));
            eraser_set_thickness(tool_get(toolbox->tool), max(size - 1, 1));
        }
        return true;
    }
    return false;
}

bool toolbox_on_mouse_click(toolbox_t *toolbox, sfEvent *event)
{
    if (on_grow(toolbox, event) || on_shrink(toolbox, event))
        return true;
    return false;
}
