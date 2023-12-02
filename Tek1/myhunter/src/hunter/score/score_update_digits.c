/*
** EPITECH PROJECT, 2022
** score_update_digits.c
** File description:
** score_update_digits.c
*/

#include "hunter.h"
#include "my.h"

static void score_destroy_digits(scene_t *scene)
{
    score_data_t *data = scene->data;

    for (uint32_t i = 0; data->digits[i]; i++) {
        scene_remove_child(scene, data->digits[i]);
        data->digits[i] = NULL;
    }
}

static void score_add_digit(scene_t *scene, uint32_t i, uint8_t digit)
{
    image_args_t *args = my_malloc(sizeof(image_args_t));
    score_data_t *data = scene->data;

    args->position = (sfVector2f){728 + 15 * i, 481};
    args->texture = data->digits_texture;
    args->texture_rect = (sfIntRect){12 * digit, 0, 12, 15};
    data->digits[i] = scene_add_child(scene, image_create(scene->app, args));
}

static uint8_t get_digit_count(uint32_t nb)
{
    uint8_t digits = nb == 0;

    for (; nb; nb /= 10)
        digits++;
    return digits;
}

void score_update_digits(scene_t *scene)
{
    score_data_t *data = scene->data;
    uint32_t score = data->score;

    score_destroy_digits(scene);
    for (uint32_t i = get_digit_count(score); i; i--) {
        score_add_digit(scene, i - 1, score % 10);
        score /= 10;
    }
}
