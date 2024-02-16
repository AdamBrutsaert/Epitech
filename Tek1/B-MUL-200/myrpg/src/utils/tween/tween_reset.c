/*
** EPITECH PROJECT, 2023
** tween_reset.c
** File description:
** tween_reset.c
*/

#include "utils/tween_impl.h"

void tween_reset(tween_t *tween)
{
    tween->value = tween->start;
}
