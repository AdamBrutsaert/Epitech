/*
** EPITECH PROJECT, 2023
** player_on_detach.c
** File description:
** player_on_detach.c
*/

#include "entities/player_impl.h"

static void player_on_detach_drop(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    sfSound_destroy(player->flask_sound);
    sfSoundBuffer_destroy(player->flask_sound_buffer);
}

void player_on_detach(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    animation_delete(player->idle_animation);
    animation_delete(player->walk_animation);
    sfTexture_destroy(player->texture);
    sfTexture_destroy(player->weapon_texture);
    sfSprite_destroy(player->sprite);
    sfSprite_destroy(player->weapon);
    camera_delete(player->camera);
    sfSound_destroy(player->sound);
    sfSoundBuffer_destroy(player->sound_buffer);
    inventory_destroy(player->inventory);
    sfSound_destroy(player->hit_sound);
    sfSoundBuffer_destroy(player->hit_sound_buffer);
    sfSound_destroy(player->death_sound);
    sfSoundBuffer_destroy(player->death_sound_buffer);
    sfSound_destroy(player->lvlup_sound);
    sfSoundBuffer_destroy(player->lvlup_sound_buffer);
    player_on_detach_drop(entity);
}
