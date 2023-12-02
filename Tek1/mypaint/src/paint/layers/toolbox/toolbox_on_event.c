/*
** EPITECH PROJECT, 2023
** toolbox_on_event.c
** File description:
** toolbox_on_event.c
*/

#include "private/paint/layers/toolbox.h"

static void center_buttons(context_t *ctx, toolbox_t *toolbox)
{
    sfVector2u size = sfRenderWindow_getSize(context_get_window(ctx));

    button_set_position(toolbox->grow, (sfVector2f){size.x / 2.0f - 100, 0});
    button_set_position(toolbox->shrink, (sfVector2f){size.x / 2.0f - 50, 0});
    button_set_position(toolbox->rect, (sfVector2f){size.x / 2.0f, 0});
    button_set_position(toolbox->circle, (sfVector2f){size.x / 2.0f + 50, 0});
    sfCircleShape_setPosition(toolbox->circle_shape, (sfVector2f)
        {size.x / 2.0f + 50 + 15, 15});
    sfRectangleShape_setPosition(toolbox->rect_shape, (sfVector2f)
        {size.x / 2.0f + 15, 15});
}

bool toolbox_on_event(context_t *ctx, void *data, sfEvent *event)
{
    toolbox_t *toolbox = data;

    if (event->type == sfEvtMouseMoved)
        toolbox_on_mouse_move(toolbox, event);
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft
        && (toolbox_on_mouse_click(toolbox, event)
            || toolbox_on_mouse_click2(toolbox, event)))
        context_prevent_propagation(ctx);
    if (event->type == sfEvtResized)
        center_buttons(ctx, toolbox);
    return true;
}
