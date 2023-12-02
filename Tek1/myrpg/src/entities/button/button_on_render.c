/*
** EPITECH PROJECT, 2023
** button_on_render.c
** File description:
** button_on_render.c
*/

#include "entities/button_impl.h"
#include "entities/text_impl.h"

void button_on_render(entity_t *entity)
{
    button_t *button = entity_get_data(entity);
    sfRenderWindow *window = entity_get_window(entity);

    sfRenderWindow_drawSprite(window, button->left_sprite, NULL);
    for (size_t i = 0; i < button->middle_length; i++)
        sfRenderWindow_drawSprite(window, button->middle_sprites[i], NULL);
    sfRenderWindow_drawSprite(window, button->right_sprite, NULL);
    sfRenderWindow_drawText(window, button->text, NULL);
}
