/*
** EPITECH PROJECT, 2023
** animation_add_frame.c
** File description:
** animation_add_frame.c
*/

#include "utils/animation_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(animation_t *animation)
{
    size_t capacity = animation->capacity * 2 + !animation->capacity;
    sfIntRect *frames = malloc(sizeof(sfIntRect) * capacity);

    if (frames == NULL)
        return false;
    my_memcpy(frames, animation->frames, sizeof(sfIntRect) * animation->length);
    free(animation->frames);
    animation->frames = frames;
    animation->capacity = capacity;
    return true;
}

bool animation_add_frame(animation_t *animation, sfIntRect rect)
{
    if (animation->length == animation->capacity && !grow(animation))
        return false;
    animation->frames[animation->length] = rect;
    animation->length++;
    tween_set_bounds(animation->tween, 0, animation->length);
    return true;
}
