/*
** EPITECH PROJECT, 2023
** tool_set_type.c
** File description:
** tool_set_type.c
*/

#include "private/paint/components/tool.h"

void tool_set_type(tool_t *tool, tool_type_t type)
{
    tool->type = type;
}
