/*
** EPITECH PROJECT, 2023
** tween_update.c
** File description:
** tween_update.c
*/

#include "utils/tween_impl.h"

float tween_update(tween_t *tween, float dt)
{
    tween->value += tween->speed * dt;
    if (!tween->repeat) {
        if (tween->value >= tween->end)
            tween->value = tween->end - 0.001f;
        return tween->value;
    }
    while (tween->value >= tween->end)
        tween->value = tween->start + tween->value - tween->end;
    return tween->value;
}
