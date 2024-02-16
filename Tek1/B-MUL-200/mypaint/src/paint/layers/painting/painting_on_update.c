/*
** EPITECH PROJECT, 2023
** painting_on_update.c
** File description:
** painting_on_update.c
*/

#include "private/paint/layers/painting.h"

bool painting_on_update(context_t *ctx, void *data, float dt)
{
    painting_t *painting = data;

    return tool_on_update(painting->tool, ctx, dt);
}
