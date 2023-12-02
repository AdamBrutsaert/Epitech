/*
** EPITECH PROJECT, 2023
** tool_get.c
** File description:
** tool_get.c
*/

#include "private/paint/components/tool.h"

void *tool_get(tool_t *tool)
{
    switch (tool->type) {
    case TOOL_PENCIL:
        return tool->pencil;
    case TOOL_HAND:
        return tool->hand;
    case TOOL_ERASER:
        return tool->eraser;
    }
    return NULL;
}
