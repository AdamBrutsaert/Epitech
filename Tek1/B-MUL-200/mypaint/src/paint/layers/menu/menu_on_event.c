/*
** EPITECH PROJECT, 2023
** menu_on_event.c
** File description:
** menu_on_event.c
*/

#include "private/paint/layers/menu.h"

bool menu_on_event(context_t *ctx, void *data, sfEvent *event)
{
    menu_t *menu = data;

    if (event->type == sfEvtMouseMoved)
        menu_on_mouse_move(menu, event);
    if (event->type == sfEvtMouseButtonPressed
        && event->mouseButton.button == sfMouseLeft
        && menu_on_mouse_click(menu, event))
        context_prevent_propagation(ctx);
    return true;
}
