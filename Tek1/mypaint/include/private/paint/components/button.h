/*
** EPITECH PROJECT, 2023
** button.h
** File description:
** button.h
*/

#pragma once

#include "paint/components/button.h"

struct button {
    sfRectangleShape *rect;
    sfText *text;
    sfFont *font;
    void *on_click_data;
    void (*on_click)(context_t *, void *);
};
