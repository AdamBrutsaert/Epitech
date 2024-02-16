/*
** EPITECH PROJECT, 2023
** menu.h
** File description:
** menu.h
*/

#pragma once

#include "paint/components/canvas.h"
#include "paint/components/tool.h"

layer_t *menu_create(void);

bool menu_on_attach(context_t *ctx, void *data);
void menu_on_detach(context_t *ctx, void *data);
bool menu_on_event(context_t *ctx, void *data, sfEvent *event);
bool menu_on_render(context_t *ctx, void *data);

void menu_bind_canvas(layer_t *layer, canvas_t *canvas);
void menu_bind_tool(layer_t *layer, tool_t *tool);
