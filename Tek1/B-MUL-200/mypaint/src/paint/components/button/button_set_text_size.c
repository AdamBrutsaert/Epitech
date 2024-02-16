/*
** EPITECH PROJECT, 2023
** button_set_text_size.c
** File description:
** button_set_text_size.c
*/

#include "private/paint/components/button.h"

void button_set_text_size(button_t *button, uint32_t size)
{
    sfText_setCharacterSize(button->text, size);
}
