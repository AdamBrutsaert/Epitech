/*
** EPITECH PROJECT, 2023
** button_destroy.c
** File description:
** button_destroy.c
*/

#include "private/paint/components/button.h"
#include "my/memory.h"

void button_destroy(button_t *button)
{
    if (!button)
        return;
    sfText_destroy(button->text);
    sfRectangleShape_destroy(button->rect);
    my_free(button);
}
