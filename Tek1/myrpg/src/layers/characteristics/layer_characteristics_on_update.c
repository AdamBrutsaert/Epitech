/*
** EPITECH PROJECT, 2023
** layer_characteristics_on_update.c
** File description:
** layer_characteristics_on_update.c
*/

#include "layers/characteristics_impl.h"
#include "layers/level.h"
#include "entities/player_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool set_max_life(layer_characteristics_t *characteristics,
    uint32_t value)
{
    free(characteristics->hearts);
    characteristics->hearts = my_calloc(value * sizeof(sfSprite *));
    if (!characteristics->hearts)
        return false;
    characteristics->max_life = value;
    for (size_t i = 0; i < value; i++) {
        characteristics->hearts[i] = sfSprite_create();
        if (characteristics->hearts[i] == NULL)
            return false;
        sfSprite_setTexture(characteristics->hearts[i],
            characteristics->texture, sfTrue);
        sfSprite_setTextureRect(characteristics->hearts[i],
            (sfIntRect){0, 0, 48, 48});
        sfSprite_setPosition(characteristics->hearts[i],
            (sfVector2f){20 + i * 60, 80});
    }
    return true;
}

static bool set_life(layer_characteristics_t *characteristics, uint32_t value)
{
    for (size_t i = 0; i < value; i++) {
        sfSprite_setTextureRect(characteristics->hearts[i],
            (sfIntRect){48, 0, 48, 48});
    }
    for (size_t i = value; i < characteristics->max_life; i++) {
        sfSprite_setTextureRect(characteristics->hearts[i],
            (sfIntRect){0, 0, 48, 48});
    }
    characteristics->life = value;
    return true;
}

bool layer_characteristics_on_update(layer_t *layer, float dt)
{
    layer_characteristics_t *data = layer_get_data(layer);
    player_t *player = entity_get_data(level_get_player(data->level));

    if (data->max_life != player->max_life) {
        return set_max_life(data, player->max_life)
            && set_life(data, player->life);
    }
    if (data->life != player->life)
        return set_life(data, player->life);
    return true;
}
