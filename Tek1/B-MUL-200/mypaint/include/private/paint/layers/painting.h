/*
** EPITECH PROJECT, 2023
** painting.h
** File description:
** painting.h
*/

#pragma once

#include "paint/layers/painting.h"
#include "paint/components/canvas.h"
#include "paint/components/tool.h"

typedef struct {
    canvas_t *canvas;
    tool_t *tool;
} painting_t;
