/*
** EPITECH PROJECT, 2023
** tween_is_over.c
** File description:
** tween_is_over.c
*/

#include "utils/tween_impl.h"

bool tween_is_over(tween_t *tween)
{
    if (tween->repeat)
        return false;
    return tween->value >= tween->end - 0.001f;
}
