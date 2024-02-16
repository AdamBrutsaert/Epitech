/*
** EPITECH PROJECT, 2023
** button_set_text_color.c
** File description:
** button_set_text_color.c
*/

#include "private/paint/components/button.h"

void button_set_text_color(button_t *button, sfColor color)
{
    sfText_setColor(button->text, color);
}
