/*
** EPITECH PROJECT, 2023
** eraser.h
** File description:
** eraser.h
*/

#pragma once

#include "paint/components/canvas.h"

typedef struct eraser eraser_t;

eraser_t *eraser_create(context_t *ctx, canvas_t *canvas);
void eraser_destroy(eraser_t *eraser);

bool eraser_on_event(context_t *ctx, eraser_t *eraser, sfEvent *event);
bool eraser_on_update(context_t *ctx, eraser_t *eraser, float dt);

float eraser_get_thickness(eraser_t *eraser);
void eraser_set_thickness(eraser_t *eraser, float size);

bool eraser_is_rect(eraser_t *pencil);
void eraser_set_rect(eraser_t *pencil, bool rect);
