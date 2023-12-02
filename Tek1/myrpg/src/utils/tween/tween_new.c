/*
** EPITECH PROJECT, 2023
** tween_new.c
** File description:
** tween_new.c
*/

#include "utils/tween_impl.h"

#include <stdlib.h>

tween_t *tween_new(float start, float end, float speed, bool repeat)
{
    tween_t *tween = malloc(sizeof(tween_t));

    if (tween == NULL)
        return NULL;
    if (start > end || speed < 0) {
        tween_delete(tween);
        return NULL;
    }
    tween->start = start;
    tween->end = end;
    tween->speed = speed;
    tween->repeat = repeat;
    tween->value = start;
    return tween;
}
