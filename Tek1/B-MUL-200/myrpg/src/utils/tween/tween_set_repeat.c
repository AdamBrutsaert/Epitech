/*
** EPITECH PROJECT, 2023
** tween_set_repeat.c
** File description:
** tween_set_repeat.c
*/

#include "utils/tween_impl.h"

void tween_set_repeat(tween_t *tween, bool repeat)
{
    tween->repeat = repeat;
}
