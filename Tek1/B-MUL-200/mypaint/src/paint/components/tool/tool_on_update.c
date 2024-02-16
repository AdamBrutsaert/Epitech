/*
** EPITECH PROJECT, 2023
** tool_on_update.c
** File description:
** tool_on_update.c
*/

#include "private/paint/components/tool.h"

bool tool_on_update(tool_t *tool, context_t *ctx, float dt)
{
    switch (tool->type) {
    case TOOL_PENCIL:
        return pencil_on_update(ctx, tool->pencil, dt);
    case TOOL_ERASER:
        return eraser_on_update(ctx, tool->eraser, dt);
    case TOOL_HAND:
        return hand_on_update(ctx, tool->hand, dt);
    }
    return true;
}
