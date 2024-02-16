/*
** EPITECH PROJECT, 2023
** painting.h
** File description:
** painting.h
*/

#pragma once

#include "paint/components/canvas.h"
#include "paint/components/tool.h"

layer_t *painting_create(void);

bool painting_on_attach(context_t *ctx, void *data);
void painting_on_detach(context_t *ctx, void *data);
bool painting_on_event(context_t *ctx, void *data, sfEvent *event);
bool painting_on_update(context_t *ctx, void *data, float dt);
bool painting_on_render(context_t *ctx, void *data);

canvas_t *painting_get_canvas(layer_t *layer);
tool_t *painting_get_tool(layer_t *layer);
