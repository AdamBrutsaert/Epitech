/*
** EPITECH PROJECT, 2023
** menu_on_detach.c
** File description:
** menu_on_detach.c
*/

#include "private/paint/layers/menu.h"

void menu_on_detach(__attribute__((unused)) context_t *ctx, void *data)
{
    menu_t *menu = data;

    sfFont_destroy(menu->font);
    button_destroy(menu->file);
    button_destroy(menu->edition);
    button_destroy(menu->help);
    button_destroy(menu->file_new);
    button_destroy(menu->file_open);
    button_destroy(menu->file_save);
    button_destroy(menu->edition_pencil);
    button_destroy(menu->edition_eraser);
    button_destroy(menu->edition_hand);
}
