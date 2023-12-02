/*
** EPITECH PROJECT, 2023
** painting_get_tool.c
** File description:
** painting_get_tool.c
*/

#include "private/paint/layers/painting.h"

tool_t *painting_get_tool(layer_t *layer)
{
    painting_t *painting = layer_get_data(layer);

    return painting->tool;
}
