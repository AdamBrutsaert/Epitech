/*
** EPITECH PROJECT, 2023
** pencil_get_thickness.c
** File description:
** pencil_get_thickness.c
*/

#include "private/paint/components/tools/pencil.h"

float pencil_get_thickness(pencil_t *pencil)
{
    return sfCircleShape_getRadius(pencil->shape);
}
