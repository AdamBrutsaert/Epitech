/*
** EPITECH PROJECT, 2023
** button_set_size.c
** File description:
** button_set_size.c
*/

#include "private/paint/components/button.h"

void button_set_size(button_t *button, sfVector2f size)
{
    sfRectangleShape_setSize(button->rect, size);
}
