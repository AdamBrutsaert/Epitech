/*
** EPITECH PROJECT, 2022
** radar_check_resources.c
** File description:
** radar_check_resources.c
*/

#include "radar.h"

static int8_t check_texture(char const *path)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);

    if (texture == NULL)
        return 84;
    sfTexture_destroy(texture);
    return 0;
}

static int8_t check_font(char const *path)
{
    sfFont *font = sfFont_createFromFile(path);

    if (font == NULL)
        return 84;
    sfFont_destroy(font);
    return 0;
}

int8_t radar_check_resources(void)
{
    int32_t sum = 0;

    sum += check_texture("res/planisphere.jpg");
    sum += check_texture("res/aircraft.png");
    sum += check_texture("res/tower.png");
    sum += check_font("res/font.ttf");
    return (sum != 0) * 84;
}
