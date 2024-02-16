/*
** EPITECH PROJECT, 2023
** canvas.h
** File description:
** canvas.h
*/

#pragma once

#include "engine/context.h"

typedef struct canvas canvas_t;

canvas_t *canvas_create(context_t *ctx);
void canvas_destroy(canvas_t *canvas);

bool canvas_on_event(context_t *ctx, canvas_t *canvas, sfEvent *event);
bool canvas_on_render(context_t *ctx, canvas_t *canvas);

sfRenderTexture *canvas_get_texture(canvas_t *canvas);
sfView *canvas_get_view(canvas_t *canvas);
bool canvas_set_size(canvas_t *canvas, sfVector2f size);
void canvas_move(canvas_t *canvas, sfVector2f offset);
void canvas_zoom(canvas_t *canvas, float factor);

void canvas_save(canvas_t *canvas);
void canvas_open(canvas_t *canvas);
void canvas_clear(canvas_t *canvas);
