/*
** EPITECH PROJECT, 2023
** pencil.h
** File description:
** pencil.h
*/

#pragma once

#include "paint/components/canvas.h"

typedef struct pencil pencil_t;

pencil_t *pencil_create(context_t *ctx, canvas_t *canvas);
void pencil_destroy(pencil_t *pencil);

bool pencil_on_event(context_t *ctx, pencil_t *pencil, sfEvent *event);
bool pencil_on_update(context_t *ctx, pencil_t *pencil, float dt);

float pencil_get_thickness(pencil_t *pencil);
void pencil_set_thickness(pencil_t *pencil, float size);

bool pencil_is_rect(pencil_t *pencil);
void pencil_set_rect(pencil_t *pencil, bool rect);
