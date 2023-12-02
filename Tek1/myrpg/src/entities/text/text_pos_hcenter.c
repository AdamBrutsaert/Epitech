/*
** EPITECH PROJECT, 2023
** text_pos_hcenter.c
** File description:
** text_pos_hcenter.c
*/

#include "entities/text_impl.h"
#include "rpg.h"

#include <stdio.h>

void text_pos_hcenter(entity_t *entity)
{
    text_t *text = entity_get_data(entity);
    sfText *sf_text = text->text;
    sfFloatRect bounds = sfText_getLocalBounds(sf_text);
    sfRenderWindow *window = entity_get_window(entity);
    sfVector2u window_size = sfRenderWindow_getSize(window);

    sfText_setPosition(sf_text, (sfVector2f) {
        (window_size.x / 2) - (bounds.width / 2),
        sfText_getPosition(sf_text).y
    });
}
