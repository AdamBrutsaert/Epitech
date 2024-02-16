/*
** EPITECH PROJECT, 2023
** menu.h
** File description:
** menu.h
*/

#pragma once

#include "paint/layers/menu.h"
#include "paint/components/button.h"

typedef enum {
    NONE = 0,
    FILE,
    EDITION,
    HELP
} selected_button_t;

typedef struct {
    canvas_t *canvas;
    tool_t *tool;
    sfFont *font;

    button_t *file;
    button_t *edition;
    button_t *help;
    selected_button_t selected;

    button_t *file_new;
    button_t *file_open;
    button_t *file_save;

    button_t *edition_pencil;
    button_t *edition_eraser;
    button_t *edition_hand;
} menu_t;

void menu_reset_buttons(menu_t *menu);

void menu_on_mouse_move(menu_t *menu, sfEvent *event);
bool menu_on_mouse_click(menu_t *menu, sfEvent *event);
