/*
** EPITECH PROJECT, 2023
** button_set_outline_color.c
** File description:
** button_set_outline_color.c
*/

#include "private/paint/components/button.h"

void button_set_outline_color(button_t *button, sfColor color)
{
    sfRectangleShape_setOutlineColor(button->rect, color);
}
