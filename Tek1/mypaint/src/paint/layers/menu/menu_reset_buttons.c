/*
** EPITECH PROJECT, 2023
** menu_reset_buttons.c
** File description:
** menu_reset_buttons.c
*/

#include "private/paint/layers/menu.h"

static void reset_button(button_t *button)
{
    button_set_color(button, sfColor_fromRGB(26, 26, 26));
    button_set_text_color(button, sfWhite);
    button_set_outline_color(button, sfTransparent);
}

void menu_reset_buttons(menu_t *menu)
{
    if (menu->selected != FILE)
        reset_button(menu->file);
    if (menu->selected != EDITION)
        reset_button(menu->edition);
    if (menu->selected != HELP)
        reset_button(menu->help);
    reset_button(menu->file_new);
    reset_button(menu->file_open);
    reset_button(menu->file_save);
    reset_button(menu->edition_pencil);
    reset_button(menu->edition_eraser);
    reset_button(menu->edition_hand);
}
