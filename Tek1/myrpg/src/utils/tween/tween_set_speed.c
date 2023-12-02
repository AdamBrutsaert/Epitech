/*
** EPITECH PROJECT, 2023
** tween_set_speed.c
** File description:
** tween_set_speed.c
*/

#include "utils/tween_impl.h"

void tween_set_speed(tween_t *tween, float speed)
{
    tween->speed = speed < 0 ? 0 : speed;
}
