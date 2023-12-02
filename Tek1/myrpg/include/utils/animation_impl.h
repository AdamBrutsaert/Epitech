/*
** EPITECH PROJECT, 2023
** animation_impl.h
** File description:
** animation_impl.h
*/

#pragma once

#include "animation.h"
#include "tween.h"

struct animation {
    sfIntRect *frames;
    size_t length;
    size_t capacity;

    tween_t *tween;
    size_t current_frame;
    float elapsed;
};
