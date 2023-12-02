/*
** EPITECH PROJECT, 2023
** tween_impl.h
** File description:
** tween_impl.h
*/

#pragma once

#include "tween.h"

struct tween {
    float start;
    float end;
    float speed;
    bool repeat;
    float value;
};
