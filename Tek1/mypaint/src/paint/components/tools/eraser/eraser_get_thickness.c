/*
** EPITECH PROJECT, 2023
** eraser_get_thickness.c
** File description:
** eraser_get_thickness.c
*/

#include "private/paint/components/tools/eraser.h"

float eraser_get_thickness(eraser_t *eraser)
{
    return sfCircleShape_getRadius(eraser->shape);
}
