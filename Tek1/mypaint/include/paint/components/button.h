/*
** EPITECH PROJECT, 2023
** button.h
** File description:
** button.h
*/

#pragma once

#include "engine/context.h"

typedef struct button button_t;

button_t *button_create(context_t *ctx, sfFont *font);
void button_destroy(button_t *button);

bool button_on_render(context_t *ctx, button_t *button);

void button_set_text(button_t *button, const char *text);
void button_set_text_position(button_t *button, sfVector2f position);
void button_set_text_size(button_t *button, uint32_t size);
void button_set_text_color(button_t *button, sfColor color);

void button_set_size(button_t *button, sfVector2f size);
void button_set_position(button_t *button, sfVector2f position);
void button_set_color(button_t *button, sfColor color);

void button_set_outline_color(button_t *button, sfColor color);

bool button_contains(button_t *button, float x, float y);
