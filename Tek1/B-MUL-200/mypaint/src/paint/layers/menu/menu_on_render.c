/*
** EPITECH PROJECT, 2023
** menu_on_render.c
** File description:
** menu_on_render.c
*/

#include "private/paint/layers/menu.h"

bool menu_on_render(context_t *ctx, void *data)
{
    menu_t *menu = data;

    if (!button_on_render(ctx, menu->file)
        || !button_on_render(ctx, menu->edition)
        || !button_on_render(ctx, menu->help))
        return false;
    if (menu->selected == FILE
        && (!button_on_render(ctx, menu->file_new)
        || !button_on_render(ctx, menu->file_open)
        || !button_on_render(ctx, menu->file_save)))
        return false;
    if (menu->selected == EDITION
        && (!button_on_render(ctx, menu->edition_pencil)
        || !button_on_render(ctx, menu->edition_eraser)
        || !button_on_render(ctx, menu->edition_hand)))
        return false;
    return true;
}
