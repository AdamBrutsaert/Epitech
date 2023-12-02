/*
** EPITECH PROJECT, 2023
** button_set_text_position.c
** File description:
** button_set_text_position.c
*/

#include "private/paint/components/button.h"

void button_set_text_position(button_t *button, sfVector2f pos)
{
    sfText_setPosition(button->text, pos);
}
