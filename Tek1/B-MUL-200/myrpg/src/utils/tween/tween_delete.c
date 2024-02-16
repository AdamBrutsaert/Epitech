/*
** EPITECH PROJECT, 2023
** tween_delete.c
** File description:
** tween_delete.c
*/

#include "utils/tween_impl.h"

#include <stdlib.h>

void tween_delete(tween_t *tween)
{
    free(tween);
}
