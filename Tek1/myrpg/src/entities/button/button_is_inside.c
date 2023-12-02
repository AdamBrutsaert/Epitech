/*
** EPITECH PROJECT, 2023
** button_is_inside.c
** File description:
** button_is_inside.c
*/

#include "entities/button_impl.h"

bool button_is_inside(entity_t *entity, sfVector2f pos)
{
    button_t *button = entity_get_data(entity);
    sfSprite *left = button->left_sprite;
    sfFloatRect left_rect = sfSprite_getGlobalBounds(left);
    sfSprite *middle;
    sfFloatRect middle_rect;
    sfSprite *right = button->right_sprite;
    sfFloatRect right_rect = sfSprite_getGlobalBounds(right);

    if (pos.x < left_rect.left || pos.x > right_rect.left + right_rect.width)
        return false;
    if (pos.y < left_rect.top || pos.y > left_rect.top + left_rect.height)
        return false;
    for (size_t i = 0; i < button->middle_length; i++) {
        middle = button->middle_sprites[i];
        middle_rect = sfSprite_getGlobalBounds(middle);
        if (pos.x > middle_rect.left && pos.x < middle_rect.left
            + middle_rect.width)
            return true;
    }
    return false;
}
