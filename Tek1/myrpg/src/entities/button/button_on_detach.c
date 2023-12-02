/*
** EPITECH PROJECT, 2023
** button_on_detach.c
** File description:
** button_on_detach.c
*/

#include "entities/button_impl.h"

#include <stdio.h>
#include <stdlib.h>

void button_on_detach(entity_t *entity)
{
    button_t *button = entity_get_data(entity);

    sfTexture_destroy(button->left_texture);
    sfSprite_destroy(button->left_sprite);
    for (size_t i = 0; i < button->middle_length; i++)
        sfSprite_destroy(button->middle_sprites[i]);
    free(button->middle_sprites);
    sfTexture_destroy(button->middle_texture);
    sfTexture_destroy(button->right_texture);
    sfSprite_destroy(button->right_sprite);
    sfText_destroy(button->text);
    sfSound_destroy(button->sound);
    sfSoundBuffer_destroy(button->sound_buffer);
}
