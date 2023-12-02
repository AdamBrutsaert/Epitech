/*
** EPITECH PROJECT, 2023
** camera_impl.h
** File description:
** camera_impl.h
*/

#pragma once

#include "camera.h"

#define SMOOTH_ACCELERATION 1.5f

struct camera {
    sfView *view;
    sfVector2f previous_center;
    sfVector2f target_delta;
    sfVector2f size;
    float zoom;
    float interpolation;
};
