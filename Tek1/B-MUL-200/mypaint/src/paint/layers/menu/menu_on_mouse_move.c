/*
** EPITECH PROJECT, 2023
** menu_on_mouse_move.c
** File description:
** menu_on_mouse_move.c
*/

#include "private/paint/layers/menu.h"

static void set_button(button_t *button)
{
    button_set_color(button, sfColor_fromRGB(24, 50, 75));
    button_set_outline_color(button, sfTransparent);
    button_set_text_color(button, sfWhite);
}

static void on_file_selected(menu_t *menu, sfEvent *event)
{
    if (button_contains(menu->file_new, event->mouseMove.x,
        event->mouseMove.y)) {
        set_button(menu->file_new);
    }
    if (button_contains(menu->file_open, event->mouseMove.x,
        event->mouseMove.y))
        set_button(menu->file_open);
    if (button_contains(menu->file_save, event->mouseMove.x,
        event->mouseMove.y))
        set_button(menu->file_save);
}

static void on_edition_selected(menu_t *menu, sfEvent *event)
{
    if (button_contains(menu->edition_eraser, event->mouseMove.x,
        event->mouseMove.y)) {
        set_button(menu->edition_eraser);
    }
    if (button_contains(menu->edition_pencil, event->mouseMove.x,
        event->mouseMove.y))
        set_button(menu->edition_pencil);
    if (button_contains(menu->edition_hand, event->mouseMove.x,
        event->mouseMove.y))
        set_button(menu->edition_hand);
}

void menu_on_mouse_move(menu_t *menu, sfEvent *event)
{
    menu_reset_buttons(menu);
    if (menu->selected != FILE
        && button_contains(menu->file, event->mouseMove.x, event->mouseMove.y))
        set_button(menu->file);
    if (menu->selected != EDITION
        && button_contains(menu->edition, event->mouseMove.x,
            event->mouseMove.y))
        set_button(menu->edition);
    if (menu->selected != HELP
        && button_contains(menu->help, event->mouseMove.x, event->mouseMove.y))
        set_button(menu->help);
    if (menu->selected == FILE)
        on_file_selected(menu, event);
    if (menu->selected == EDITION)
        on_edition_selected(menu, event);
}
