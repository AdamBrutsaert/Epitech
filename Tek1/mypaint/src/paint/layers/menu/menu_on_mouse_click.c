/*
** EPITECH PROJECT, 2023
** menu_on_mouse_click.c
** File description:
** menu_on_mouse_click.c
*/

#include "private/paint/layers/menu.h"
#include "private/paint/app.h"

static bool set_button(menu_t *menu, button_t *button,
    selected_button_t selected)
{
    menu->selected = selected;
    menu_reset_buttons(menu);
    button_set_color(button, sfColor_fromRGB(24, 50, 75));
    button_set_outline_color(button, sfColor_fromRGB(8, 85, 162));
    button_set_text_color(button, sfWhite);
    return true;
}

static bool on_file_selected(menu_t *menu, sfEvent *event)
{
    if (button_contains(menu->file_new, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->canvas)
            canvas_clear(menu->canvas);
        return true;
    }
    if (button_contains(menu->file_open, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->canvas)
            canvas_open(menu->canvas);
        return true;
    }
    if (button_contains(menu->file_save, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->canvas)
            canvas_save(menu->canvas);
        return true;
    }
    return false;
}

static bool on_edition_selected(menu_t *menu, sfEvent *event)
{
    if (button_contains(menu->edition_pencil, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->tool)
            tool_set_type(menu->tool, TOOL_PENCIL);
        return true;
    }
    if (button_contains(menu->edition_hand, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->tool)
            tool_set_type(menu->tool, TOOL_HAND);
        return true;
    }
    if (button_contains(menu->edition_eraser, event->mouseButton.x,
        event->mouseButton.y)) {
        if (menu->tool)
            tool_set_type(menu->tool, TOOL_ERASER);
        return true;
    }
    return false;
}

bool menu_on_mouse_click(menu_t *menu, sfEvent *event)
{
    selected_button_t selected = menu->selected;

    if (button_contains(menu->file, event->mouseButton.x, event->mouseButton.y))
        return set_button(menu, menu->file, FILE);
    if (button_contains(menu->edition, event->mouseButton.x,
        event->mouseButton.y))
        return set_button(menu, menu->edition, EDITION);
    if (button_contains(menu->help, event->mouseButton.x, event->mouseButton.y))
        return app_help();
    menu->selected = NONE;
    menu_reset_buttons(menu);
    if (selected == FILE)
        return on_file_selected(menu, event);
    if (selected == EDITION)
        return on_edition_selected(menu, event);
    return false;
}
