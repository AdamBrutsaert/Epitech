/*
** EPITECH PROJECT, 2023
** button_on_attach.c
** File description:
** button_on_attach.c
*/

#include "entities/button_impl.h"

#include <stdio.h>

static bool create_sound(button_t *button)
{
    button->sound_buffer = sfSoundBuffer_createFromFile(RES(
        "sounds/click.ogg"));
    if (!button->sound_buffer)
        return false;
    button->sound = sfSound_create();
    if (!button->sound)
        return false;
    sfSound_setBuffer(button->sound, button->sound_buffer);
    return true;
}

static bool load_skin(button_t *button)
{
    if (button->skin == BUTTON_SKIN_BROWN) {
        button->left_texture =
            sfTexture_createFromFile(RES("ui/button/b_i_left.png"), NULL);
        button->middle_texture =
            sfTexture_createFromFile(RES("ui/button/b_i_body.png"), NULL);
        button->right_texture =
            sfTexture_createFromFile(RES("ui/button/b_i_right.png"), NULL);
    }
    return button->left_texture && button->middle_texture;
}

static bool add_middle_part(button_t *button, size_t pos)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite)
        return false;
    sfSprite_setTexture(sprite, button->middle_texture, sfTrue);
    sfSprite_setTextureRect(sprite, (sfIntRect){0, 0, 49, 42});
    button->middle_sprites[pos] = sprite;
    button->middle_length++;
    return true;
}

static bool init_text(button_t *button)
{
    button->text = sfText_create();
    if (!button->text)
        return false;
    sfText_setFont(button->text, button->font);
    sfText_setCharacterSize(button->text, 16);
    sfText_setColor(button->text, sfWhite);
    sfText_setString(button->text, "");
    return true;
}

bool button_on_attach(entity_t *entity)
{
    button_t *button = entity_get_data(entity);

    if (!load_skin(button) || !init_text(button))
        return false;
    button->left_sprite = sfSprite_create();
    button->right_sprite = sfSprite_create();
    if (!button->left_sprite || !button->right_sprite)
        return false;
    sfSprite_setTexture(button->left_sprite, button->left_texture, sfTrue);
    sfSprite_setTextureRect(button->left_sprite, (sfIntRect){0, 0, 12, 42});
    sfSprite_setTexture(button->right_sprite, button->right_texture, sfTrue);
    sfSprite_setTextureRect(button->right_sprite, (sfIntRect){0, 0, 12, 42});
    for (size_t i = 0; i < button->parts; i++)
        if (!add_middle_part(button, i))
            return false;
    button_set_position(entity, 0, 0);
    return create_sound(button);
}
