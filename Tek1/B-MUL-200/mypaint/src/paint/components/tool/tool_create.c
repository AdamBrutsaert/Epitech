/*
** EPITECH PROJECT, 2023
** tool_create.c
** File description:
** tool_create.c
*/

#include "private/paint/components/tool.h"
#include "my/memory.h"

static bool create(tool_t *tool, context_t *ctx, canvas_t *canvas)
{
    tool->type = TOOL_PENCIL;
    tool->pencil = pencil_create(ctx, canvas);
    tool->eraser = eraser_create(ctx, canvas);
    tool->hand = hand_create(ctx, canvas);

    return tool->pencil;
}

tool_t *tool_create(context_t *ctx, canvas_t *canvas)
{
    tool_t *tool = my_calloc(sizeof(tool_t));

    if (!tool)
        return NULL;
    if (!create(tool, ctx, canvas)) {
        tool_destroy(tool);
        return NULL;
    }
    return tool;
}
