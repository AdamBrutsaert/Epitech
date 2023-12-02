/*
** EPITECH PROJECT, 2023
** button_on_render.c
** File description:
** button_on_render.c
*/

#include "private/paint/components/button.h"

bool button_on_render(context_t *ctx, button_t *button)
{
    sfRenderStates states = {sfBlendAdd, sfTransform_Identity, NULL, NULL};
    sfVector2f pos = sfRectangleShape_getPosition(button->rect);

    sfTransform_translate(&states.transform, pos.x, pos.y);
    sfRenderWindow_drawRectangleShape(context_get_window(ctx), button->rect,
        NULL);
    sfRenderWindow_drawText(context_get_window(ctx), button->text, &states);
    return true;
}
