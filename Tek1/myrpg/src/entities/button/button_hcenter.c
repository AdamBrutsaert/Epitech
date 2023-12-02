/*
** EPITECH PROJECT, 2023
** button_hcenter.c
** File description:
** button_hcenter.c
*/

#include "entities/button_impl.h"

void button_hcenter(entity_t *entity)
{
    button_t *button = entity_get_data(entity);
    sfVector2u window_size = sfRenderWindow_getSize(entity_get_window(entity));
    sfVector2f left_pos = sfSprite_getPosition(button->left_sprite);
    sfVector2f right_pos = sfSprite_getPosition(button->right_sprite);
    sfFloatRect right_rect = sfSprite_getLocalBounds(button->right_sprite);
    float width = right_pos.x + right_rect.width - left_pos.x;

    button_set_position(entity, window_size.x / 2 - width / 2, left_pos.y);
}
