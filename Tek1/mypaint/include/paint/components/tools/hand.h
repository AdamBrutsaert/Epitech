/*
** EPITECH PROJECT, 2023
** hand.h
** File description:
** hand.h
*/

#pragma once

#include "paint/components/canvas.h"

typedef struct hand hand_t;

hand_t *hand_create(context_t *ctx, canvas_t *canvas);
void hand_destroy(hand_t *hand);

bool hand_on_event(context_t *ctx, hand_t *hand, sfEvent *event);
bool hand_on_update(context_t *ctx, hand_t *hand, float dt);
