/*
** EPITECH PROJECT, 2023
** tool.h
** File description:
** tool.h
*/

#pragma once

#include "paint/components/tool.h"
#include "paint/components/tools/pencil.h"
#include "paint/components/tools/eraser.h"
#include "paint/components/tools/hand.h"

struct tool {
    tool_type_t type;
    pencil_t *pencil;
    eraser_t *eraser;
    hand_t *hand;
};
