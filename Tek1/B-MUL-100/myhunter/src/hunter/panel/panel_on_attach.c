/*
** EPITECH PROJECT, 2022
** panel_on_attach.c
** File description:
** panel_on_attach.c
*/

#include "hunter.h"
#include "my.h"

static char *u64_to_str(uint64_t nb)
{
    char *str = my_calloc(10);

    for (uint64_t i = 9; i; i--) {
        str[i - 1] = '0' + nb % 10;
        nb /= 10;
    }
    return str;
}

static void panel_set_text(scene_t *scene)
{
    panel_data_t *data = scene->data;
    panel_args_t *args = scene->args;
    char *str = u64_to_str(args->score);

    data->text = sfText_create();
    sfText_setFont(data->text, data->font);
    sfText_setString(data->text, args->lost ? "You lost" : "You won");
    sfText_setCharacterSize(data->text, 16);
    sfText_setPosition(data->text, (sfVector2f){390.0f, 180.0f});
    data->title = sfText_create();
    sfText_setFont(data->title, data->font);
    sfText_setString(data->title, "Score");
    sfText_setCharacterSize(data->title, 16);
    sfText_setPosition(data->title, (sfVector2f){402.0f, 250.0f});
    data->score = sfText_create();
    sfText_setFont(data->score, data->font);
    sfText_setString(data->score, str);
    sfText_setCharacterSize(data->score, 16);
    sfText_setPosition(data->score, (sfVector2f){380.0f, 290.0f});
    my_free(str);
}

void panel_on_attach(scene_t *scene)
{
    panel_data_t *data = scene->data;

    data->font = sfFont_createFromFile("res/Broken Console Regular.ttf");
    data->texture = sfTexture_createFromFile("res/panel.png", NULL);
    data->sprite = sfSprite_create();
    panel_set_text(scene);
    sfSprite_setTexture(data->sprite, data->texture, sfTrue);
    sfSprite_setPosition(data->sprite, (sfVector2f){304.0f, 105.0f});
}
