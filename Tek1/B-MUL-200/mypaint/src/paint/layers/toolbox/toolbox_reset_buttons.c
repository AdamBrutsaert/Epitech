/*
** EPITECH PROJECT, 2023
** toolbox_reset_buttons.c
** File description:
** toolbox_reset_buttons.c
*/

#include "private/paint/layers/toolbox.h"

void toolbox_reset_button(button_t *button)
{
    button_set_color(button, sfColor_fromRGB(26, 26, 26));
    button_set_text_color(button, sfWhite);
    button_set_outline_color(button, sfTransparent);
}
