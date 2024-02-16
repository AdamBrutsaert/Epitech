/*
** EPITECH PROJECT, 2023
** toolbox_on_update.c
** File description:
** toolbox_on_update.c
*/

#include "private/paint/layers/toolbox.h"
#include "paint/components/tools/pencil.h"
#include "paint/components/tools/eraser.h"

static void set(button_t *button)
{
    button_set_color(button, sfColor_fromRGB(24, 50, 75));
    button_set_outline_color(button, sfColor_fromRGB(8, 85, 162));
}

static void for_pencil(toolbox_t *toolbox)
{
    if (tool_get_type(toolbox->tool) == TOOL_PENCIL) {
        if (pencil_is_rect(tool_get(toolbox->tool))) {
            set(toolbox->rect);
        } else {
            set(toolbox->circle);
        }
    }
}

static void for_eraser(toolbox_t *toolbox)
{
    if (tool_get_type(toolbox->tool) == TOOL_ERASER) {
        if (eraser_is_rect(tool_get(toolbox->tool))) {
            set(toolbox->rect);
        } else {
            set(toolbox->circle);
        }
    }
}

bool toolbox_on_update(__attribute__((unused)) context_t *ctx, void *data,
    __attribute__((unused)) float dt)
{
    toolbox_t *toolbox = data;

    if (!toolbox->tool)
        return true;
    for_pencil(toolbox);
    for_eraser(toolbox);
    return true;
}
