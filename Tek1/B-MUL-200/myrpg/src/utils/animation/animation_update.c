/*
** EPITECH PROJECT, 2023
** animation_update.c
** File description:
** animation_update.c
*/

#include "utils/animation_impl.h"

#include <stdint.h>

sfIntRect *animation_update(animation_t *animation, float dt)
{
    uint64_t progress = tween_update(animation->tween, dt);

    if (animation->length == 0)
        return NULL;
    if (progress == animation->length)
        progress = animation->length - 1;
    return &animation->frames[progress];
}
