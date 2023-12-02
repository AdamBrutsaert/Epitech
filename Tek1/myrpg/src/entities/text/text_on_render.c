/*
** EPITECH PROJECT, 2023
** text_on_render.c
** File description:
** text_on_render.c
*/

#include "entities/text_impl.h"

void text_on_render(entity_t *entity)
{
    text_t *text = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawText(window, text->text, NULL);
}
