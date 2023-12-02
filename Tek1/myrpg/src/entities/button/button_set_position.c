/*
** EPITECH PROJECT, 2023
** button_set_position.c
** File description:
** button_set_position.c
*/

#include "entities/button_impl.h"

static void set_text(button_t *button)
{
    sfVector2f left_end_rect_pos = sfSprite_getPosition(button->left_sprite);
    sfFloatRect left_end_rect = sfSprite_getGlobalBounds(button->left_sprite);
    sfVector2f right_end_rect_pos = sfSprite_getPosition(button->right_sprite);
    sfFloatRect text_rect = sfText_getGlobalBounds(button->text);

    left_end_rect_pos.x += left_end_rect.width;
    sfText_setPosition(button->text, (sfVector2f){
        left_end_rect_pos.x + (right_end_rect_pos.x - left_end_rect_pos.x
        - text_rect.width) / 2,
        left_end_rect_pos.y + (left_end_rect.height - text_rect.height) / 2});
}

void button_set_position(entity_t *entity, float x, float y)
{
    button_t *button = entity_get_data(entity);
    sfSprite *left = button->left_sprite;
    sfFloatRect left_rect = sfSprite_getGlobalBounds(left);
    sfSprite *middle;
    sfFloatRect middle_rect;
    sfVector2f middle_pos;

    sfSprite_setPosition(left, (sfVector2f){x, y});
    for (size_t i = 0; i < button->middle_length; i++) {
        middle = button->middle_sprites[i];
        middle_rect = sfSprite_getGlobalBounds(middle);
        middle_pos = (sfVector2f) {x + left_rect.width, y};
        middle_pos.x += middle_rect.width * i;
        sfSprite_setPosition(middle, middle_pos);
    }
    sfSprite_setPosition(button->right_sprite, (sfVector2f){x + left_rect.width
        + middle_rect.width * button->middle_length, y});
    sfText_setPosition(button->text, (sfVector2f){x + left_rect.width
        + middle_rect.width * button->middle_length, y});
    set_text(button);
}
