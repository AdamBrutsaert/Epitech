/*
** EPITECH PROJECT, 2023
** button_create.c
** File description:
** button_create.c
*/

#include "private/paint/components/button.h"
#include "my/memory.h"

static bool create(button_t *button)
{
    button->text = sfText_create();
    button->rect = sfRectangleShape_create();
    return button->text && button->rect;
}

static void set(button_t *button, sfFont *font)
{
    sfText_setFont(button->text, font);
    sfText_setColor(button->text, sfWhite);
    sfText_setCharacterSize(button->text, 16);
    sfRectangleShape_setFillColor(button->rect, sfColor_fromRGB(26, 26, 26));
    sfRectangleShape_setOutlineThickness(button->rect, -2);
    sfRectangleShape_setOutlineColor(button->rect, sfTransparent);
}

button_t *button_create(__attribute__((unused)) context_t *ctx, sfFont *font)
{
    button_t *button = my_calloc(sizeof(button_t));

    if (!button)
        return NULL;
    if (!create(button)) {
        button_destroy(button);
        return NULL;
    }
    set(button, font);
    return button;
}
