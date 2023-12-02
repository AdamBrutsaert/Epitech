/*
** EPITECH PROJECT, 2023
** animation_delete.c
** File description:
** animation_delete.c
*/

#include "utils/animation_impl.h"

#include <stdlib.h>

void animation_delete(animation_t *animation)
{
    if (animation == NULL)
        return;
    tween_delete(animation->tween);
    free(animation->frames);
    free(animation);
}
