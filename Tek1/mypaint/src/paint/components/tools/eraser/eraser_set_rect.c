/*
** EPITECH PROJECT, 2023
** eraser_set_rect.c
** File description:
** eraser_set_rect.c
*/

#include "private/paint/components/tools/eraser.h"

void eraser_set_rect(eraser_t *eraser, bool rect)
{
    eraser->is_rect = rect;
}
