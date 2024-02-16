/*
** EPITECH PROJECT, 2023
** text_set_position.c
** File description:
** text_set_position.c
*/

#include "entities/text_impl.h"

#include <stdio.h>

void text_set_position(entity_t *entity, sfVector2f position)
{
    text_t *text = entity_get_data(entity);
    bool center_h = position.x == TEXT_CENTER;
    bool center_v = position.y == TEXT_CENTER;

    position.x = center_h ? 0 : position.x;
    position.y = center_v ? 0 : position.y;
    sfText_setPosition(text->text, position);
    if (center_h)
        text_pos_hcenter(entity);
    if (center_v)
        text_pos_vcenter(entity);
}
