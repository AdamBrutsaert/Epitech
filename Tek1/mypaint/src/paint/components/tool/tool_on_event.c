/*
** EPITECH PROJECT, 2023
** tool_on_event.c
** File description:
** tool_on_event.c
*/

#include "private/paint/components/tool.h"

bool tool_on_event(tool_t *tool, context_t *ctx, sfEvent *event)
{
    switch (tool->type) {
    case TOOL_PENCIL:
        return pencil_on_event(ctx, tool->pencil, event);
    case TOOL_ERASER:
        return eraser_on_event(ctx, tool->eraser, event);
    case TOOL_HAND:
        return hand_on_event(ctx, tool->hand, event);
    }
    return true;
}
