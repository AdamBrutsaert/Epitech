/*
** EPITECH PROJECT, 2023
** animation_set_speed.c
** File description:
** animation_set_speed.c
*/

#include "utils/animation_impl.h"

void animation_set_speed(animation_t *animation, float speed)
{
    tween_set_speed(animation->tween, speed);
}
