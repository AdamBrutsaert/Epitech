/*
** EPITECH PROJECT, 2023
** animation_is_over.c
** File description:
** animation_is_over.c
*/

#include "utils/animation_impl.h"

bool animation_is_over(animation_t *animation)
{
    return tween_is_over(animation->tween);
}
