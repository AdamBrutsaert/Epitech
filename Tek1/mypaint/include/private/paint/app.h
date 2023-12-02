/*
** EPITECH PROJECT, 2023
** app.h
** File description:
** app.h
*/

#pragma once

#include "paint/app.h"
#include "paint/layers/painting.h"
#include "paint/layers/toolbox.h"
#include "paint/layers/menu.h"

struct app {
    context_t *ctx;
    layer_t *painting;
    layer_t *toolbox;
    layer_t *menu;
};

bool app_help(void);
