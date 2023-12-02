/*
** EPITECH PROJECT, 2022
** game_test_resources.c
** File description:
** game_test_resources.c
*/

#include "hunter.h"

static int8_t test_texture(char const *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    sfTexture_destroy(texture);
    return !texture;
}

static int8_t test_sound(char const *path)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    sfSoundBuffer_destroy(buffer);
    return !buffer;
}

static int8_t test_music(char const *path)
{
    sfMusic *music = sfMusic_createFromFile(path);
    sfMusic_destroy(music);
    return !music;
}

static int8_t test_font(char const *path)
{
    sfFont *font = sfFont_createFromFile(path);
    sfFont_destroy(font);
    return !font;
}

int8_t game_test_resources(void)
{
    int8_t errors = 0;

    errors += test_texture("res/background.png");
    errors += test_texture("res/box.png");
    errors += test_texture("res/cursor.png");
    errors += test_texture("res/digits.png");
    errors += test_texture("res/heart.png");
    errors += test_texture("res/pea.png");
    errors += test_texture("res/zombie.png");
    errors += test_texture("res/panel.png");
    errors += test_texture("res/peashooter.png");
    errors += test_sound("res/balloon_pop.ogg");
    errors += test_sound("res/floop.ogg");
    errors += test_sound("res/melonimpact.ogg");
    errors += test_sound("res/awooga.ogg");
    errors += test_music("res/Loonboon.ogg");
    errors += test_music("res/Moongrains.ogg");
    errors += test_music("res/Intro.ogg");
    errors += test_font("res/Broken Console Regular.ttf");
    return errors;
}
