/*
** EPITECH PROJECT, 2023
** button_set_text.c
** File description:
** button_set_text.c
*/

#include "private/paint/components/button.h"

void button_set_text(button_t *button, const char *text)
{
    sfText_setString(button->text, text);
}
