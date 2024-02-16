/*
** EPITECH PROJECT, 2023
** animation_set_repeat.c
** File description:
** animation_set_repeat.c
*/

#include "utils/animation_impl.h"

void animation_set_repeat(animation_t *animation, bool repeat)
{
    tween_set_repeat(animation->tween, repeat);
}
