/*
** EPITECH PROJECT, 2023
** button_set_string.c
** File description:
** button_set_string.c
*/

#include "entities/button_impl.h"


void button_set_string(entity_t *entity, char *string)
{
    button_t *button = entity_get_data(entity);
    sfVector2f position = sfSprite_getPosition(button->left_sprite);

    sfText_setString(button->text, string);
    button_set_position(entity, position.x, position.y);
}
