/*
** EPITECH PROJECT, 2023
** context.h
** File description:
** context.h
*/

#pragma once

#include "layer.h"

#include <stdint.h>

typedef struct context context_t;

context_t *context_create(uint32_t width, uint32_t height, const char *title);
void context_destroy(context_t *ctx);

sfRenderWindow *context_get_window(context_t *ctx);
void context_prevent_propagation(context_t *ctx);
void context_reset_view(context_t *ctx);
bool context_push(context_t *ctx, layer_t *layer);
void context_pop(context_t *ctx);
bool context_run(context_t *ctx);
