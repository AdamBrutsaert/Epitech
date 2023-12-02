/*
** EPITECH PROJECT, 2023
** button_impl.h
** File description:
** button_impl.h
*/

#pragma once

#include "button.h"
#include "text.h"

#include <SFML/Audio.h>

#define COOLDOWN 0.2f

struct button {
    button_skin_t skin;
    uint16_t parts;

    sfSprite *left_sprite;
    sfTexture *left_texture;

    sfSprite **middle_sprites;
    sfTexture *middle_texture;
    size_t middle_length;
    size_t middle_capacity;

    sfSprite *right_sprite;
    sfTexture *right_texture;

    sfFont *font;
    sfText *text;

    callback_t callback;

    enum { IDLE = 0, PRESSING, HOVERING } status;

    sfSound *sound;
    sfSoundBuffer *sound_buffer;

    bool call_callback;
    float cooldown;
};

bool button_on_attach(entity_t *entity);
void button_on_detach(entity_t *entity);
bool button_on_event(entity_t *entity, sfEvent *event);
bool button_on_update(entity_t *entity, float delta);
void button_on_render(entity_t *entity);
