/*
** EPITECH PROJECT, 2023
** animation_reset.c
** File description:
** animation_reset.c
*/

#include "utils/animation_impl.h"

void animation_reset(animation_t *animation)
{
    tween_reset(animation->tween);
}
