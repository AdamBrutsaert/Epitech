/*
** EPITECH PROJECT, 2023
** menu_impl.h
** File description:
** menu_impl.h
*/

#pragma once

#include "menu.h"
#include "entities/text.h"
#include "entities/button.h"

#include <SFML/Audio.h>

struct menu {
    sfFont *font;

    entity_t *title;
    entity_t *play;
    entity_t *resume;
    entity_t *config;
    entity_t *quit;

    sfMusic *music;
};

bool menu_on_attach(layer_t *layer);
void menu_on_detach(layer_t *layer);
void menu_on_render(layer_t *layer);
bool menu_on_event(layer_t *layer, sfEvent *event);

bool menu_add_buttons(layer_t *layer, menu_t *menu);

void button_menu_resume_clicked(entity_t *entity, void *data);
void button_menu_play_clicked(entity_t *entity, void *data);
void button_menu_config_clicked(entity_t *entity, void *data);
void button_menu_quit_clicked(entity_t *entity, void *data);
