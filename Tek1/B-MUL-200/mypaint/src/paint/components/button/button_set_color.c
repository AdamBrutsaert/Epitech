/*
** EPITECH PROJECT, 2023
** button_set_color.c
** File description:
** button_set_color.c
*/

#include "private/paint/components/button.h"

void button_set_color(button_t *button, sfColor color)
{
    sfRectangleShape_setFillColor(button->rect, color);
}
