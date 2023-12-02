/*
** EPITECH PROJECT, 2023
** toolbox_bind_tool.c
** File description:
** toolbox_bind_tool.c
*/

#include "private/paint/layers/toolbox.h"

void toolbox_bind_tool(layer_t *layer, tool_t *tool)
{
    toolbox_t *toolbox = layer_get_data(layer);

    toolbox->tool = tool;
}
