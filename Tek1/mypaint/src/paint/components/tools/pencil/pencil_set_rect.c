/*
** EPITECH PROJECT, 2023
** pencil_set_rect.c
** File description:
** pencil_set_rect.c
*/

#include "private/paint/components/tools/pencil.h"

void pencil_set_rect(pencil_t *pencil, bool rect)
{
    pencil->is_rect = rect;
}
