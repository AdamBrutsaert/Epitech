/*
** EPITECH PROJECT, 2023
** tool_get_type.c
** File description:
** tool_get_type.c
*/

#include "private/paint/components/tool.h"

tool_type_t tool_get_type(tool_t *tool)
{
    return tool->type;
}
