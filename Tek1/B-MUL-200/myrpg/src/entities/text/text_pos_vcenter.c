/*
** EPITECH PROJECT, 2023
** text_pos_vcenter.c
** File description:
** text_pos_vcenter.c
*/

#include "entities/text_impl.h"
#include "rpg.h"

#include <stdio.h>

void text_pos_vcenter(entity_t *entity)
{
    text_t *text = entity_get_data(entity);
    sfText *sf_text = text->text;
    sfFloatRect bounds = sfText_getLocalBounds(sf_text);
    sfRenderWindow *window = entity_get_window(entity);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfText_setPosition(sf_text, (sfVector2f) {
        sfText_getPosition(sf_text).x,
        (window_size.y / 2) - (bounds.height / 2)
    });
}
