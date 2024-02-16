/*
** EPITECH PROJECT, 2023
** menu_bind_tool.c
** File description:
** menu_bind_tool.c
*/

#include "private/paint/layers/menu.h"

void menu_bind_tool(layer_t *layer, tool_t *tool)
{
    menu_t *menu = layer_get_data(layer);

    menu->tool = tool;
}
