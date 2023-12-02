/*
** EPITECH PROJECT, 2022
** menu_on_attach.c
** File description:
** menu_on_attach.c
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

static void menu_set_text(scene_t *scene)
{
    menu_data_t *data = scene->data;
    char *score = u64_to_str(read_best_score());

    data->text = sfText_create();
    sfText_setFont(data->text, data->font);
    sfText_setCharacterSize(data->text, 20);
    sfText_setString(data->text, "Press any key to start...");
    sfText_setPosition(data->text, (sfVector2f){300.0f, 200.0f});
    data->score = sfText_create();
    sfText_setFont(data->score, data->font);
    sfText_setCharacterSize(data->score, 20);
    sfText_setString(data->score, score);
    sfText_setPosition(data->score, (sfVector2f){380.0f, 450.0f});
    my_free(score);
    data->title = sfText_create();
    sfText_setFont(data->title, data->font);
    sfText_setCharacterSize(data->title, 20);
    sfText_setString(data->title, "BEST SCORE");
    sfText_setPosition(data->title, (sfVector2f){382.0f, 420.0f});
}

void menu_on_attach(scene_t *scene)
{
    menu_data_t *data = scene->data;

    data->bg = sfTexture_createFromFile("res/background.png", NULL);
    data->sprite = sfSprite_create();
    sfSprite_setTexture(data->sprite, data->bg, sfTrue);
    data->music = sfMusic_createFromFile("res/Intro.ogg");
    sfMusic_play(data->music);
    sfMusic_setLoop(data->music, sfTrue);
    data->font = sfFont_createFromFile("res/Broken Console Regular.ttf");
    menu_set_text(scene);
    menu_update_view(scene);
}
