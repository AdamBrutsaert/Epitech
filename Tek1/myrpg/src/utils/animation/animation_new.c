/*
** EPITECH PROJECT, 2023
** animation_new.c
** File description:
** animation_new.c
*/

#include "utils/animation_impl.h"
#include "my/memory.h"

animation_t *animation_new(void)
{
    animation_t *animation = my_calloc(sizeof(animation_t));

    if (animation == NULL)
        return NULL;
    animation->tween = tween_new(0, 0, 1.0f, true);
    if (animation->tween == NULL) {
        animation_delete(animation);
        return NULL;
    }
    return animation;
}
