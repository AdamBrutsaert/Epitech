/*
** EPITECH PROJECT, 2023
** tool_destroy.c
** File description:
** tool_destroy.c
*/

#include "private/paint/components/tool.h"
#include "my/memory.h"

void tool_destroy(tool_t *tool)
{
    if (!tool)
        return;
    pencil_destroy(tool->pencil);
    eraser_destroy(tool->eraser);
    hand_destroy(tool->hand);
    my_free(tool);
}
