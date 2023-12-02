/*
** EPITECH PROJECT, 2023
** text_set.c
** File description:
** text_set.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

void text_set(entity_t *entity, char *string, sfColor color, uint16_t size)
{
    text_set_string(entity, string);
    text_set_color(entity, color);
    text_set_size(entity, size);
}
