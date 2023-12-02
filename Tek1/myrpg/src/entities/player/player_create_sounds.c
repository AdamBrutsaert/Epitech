/*
** EPITECH PROJECT, 2023
** player_create_sounds.c
** File description:
** player_create_sounds.c
*/

#include "entities/player_impl.h"

static bool create_lvlup_sound(player_t *player)
{
    player->lvlup_sound = sfSound_create();
    player->lvlup_sound_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/lvlup.ogg");
    if (!player->lvlup_sound || !player->lvlup_sound_buffer)
        return false;
    sfSound_setBuffer(player->lvlup_sound, player->lvlup_sound_buffer);
    sfSound_setVolume(player->lvlup_sound, 25);
    return true;
}

static bool create_drop_sound(player_t *player)
{
    player->flask_sound = sfSound_create();
    player->flask_sound_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/drop.ogg");
    if (!player->flask_sound || !player->flask_sound_buffer)
        return false;
    sfSound_setBuffer(player->flask_sound, player->flask_sound_buffer);
    sfSound_setVolume(player->flask_sound, 100);
    return true;
}

bool player_create_sounds(player_t *player)
{
    player->sound = sfSound_create();
    player->hit_sound = sfSound_create();
    player->death_sound = sfSound_create();
    player->sound_buffer = sfSoundBuffer_createFromFile("res/sounds/steps.ogg");
    player->hit_sound_buffer = sfSoundBuffer_createFromFile(
        "res/sounds/hit.ogg");
    player->death_sound_buffer = sfSoundBuffer_createFromFile(
    "res/sounds/death.ogg");
    if (!player->sound || !player->sound_buffer || !player->hit_sound ||
        !player->hit_sound_buffer || !player->death_sound ||
        !player->death_sound_buffer)
        return false;
    sfSound_setBuffer(player->sound, player->sound_buffer);
    sfSound_setBuffer(player->hit_sound, player->hit_sound_buffer);
    sfSound_setBuffer(player->death_sound, player->death_sound_buffer);
    sfSound_setVolume(player->sound, 75);
    sfSound_setVolume(player->hit_sound, 75);
    sfSound_setVolume(player->death_sound, 75);
    return create_lvlup_sound(player) && create_drop_sound(player);
}
