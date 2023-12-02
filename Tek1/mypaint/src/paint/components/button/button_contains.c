/*
** EPITECH PROJECT, 2023
** button_contains.c
** File description:
** button_contains.c
*/

#include "private/paint/components/button.h"

bool button_contains(button_t *button, float x, float y)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(button->rect);

    return sfFloatRect_contains(&rect, x, y);
}
