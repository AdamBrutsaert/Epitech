/*
** EPITECH PROJECT, 2023
** text_impl.h
** File description:
** text_impl.h
*/

#pragma once

#include "text.h"

struct text {
    sfFont *font;
    sfText *text;
};

bool text_on_attach(entity_t *entity);
void text_on_detach(entity_t *entity);
bool text_on_event(entity_t *entity, sfEvent *event);
void text_on_render(entity_t *entity);
