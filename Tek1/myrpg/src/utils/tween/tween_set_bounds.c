/*
** EPITECH PROJECT, 2023
** tween_set_bounds.c
** File description:
** tween_set_bounds.c
*/

#include "utils/tween_impl.h"

void tween_set_bounds(tween_t *tween, float start, float end)
{
    tween->start = start;
    tween->end = end;
    tween->value = start;
}
