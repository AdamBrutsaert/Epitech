/*
** EPITECH PROJECT, 2023
** tool.h
** File description:
** tool.h
*/

#pragma once

#include "paint/components/canvas.h"

typedef enum {
    TOOL_PENCIL,
    TOOL_ERASER,
    TOOL_HAND
} tool_type_t;

typedef struct tool tool_t;

tool_t *tool_create(context_t *ctx, canvas_t *canvas);
void tool_destroy(tool_t *tool);

void *tool_get(tool_t *tool);
tool_type_t tool_get_type(tool_t *tool);
void tool_set_type(tool_t *tool, tool_type_t type);

bool tool_on_event(tool_t *tool, context_t *ctx, sfEvent *event);
bool tool_on_update(tool_t *tool, context_t *ctx, float dt);
