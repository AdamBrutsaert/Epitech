/*
** EPITECH PROJECT, 2023
** canvas.h
** File description:
** canvas.h
*/

#pragma once

#include "paint/components/canvas.h"

struct canvas {
    sfRenderTexture *texture;
    sfSprite *sprite;

    sfView *view;
    sfVector2f center;
    float zoom;

    sfTexture *bg_texture;
    sfVertexArray *bg;
};

void canvas_update_view(canvas_t *canvas, context_t *ctx);
