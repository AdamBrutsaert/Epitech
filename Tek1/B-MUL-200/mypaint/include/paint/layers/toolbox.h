/*
** EPITECH PROJECT, 2023
** toolbox.h
** File description:
** toolbox.h
*/

#pragma once

#include "paint/components/tool.h"

layer_t *toolbox_create(void);

bool toolbox_on_attach(context_t *ctx, void *data);
void toolbox_on_detach(context_t *ctx, void *data);
bool toolbox_on_event(context_t *ctx, void *data, sfEvent *event);
bool toolbox_on_update(context_t *ctx, void *data, float dt);
bool toolbox_on_render(context_t *ctx, void *data);

void toolbox_bind_tool(layer_t *layer, tool_t *tool);
