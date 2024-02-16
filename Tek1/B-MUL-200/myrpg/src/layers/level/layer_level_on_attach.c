/*
** EPITECH PROJECT, 2023
** layer_level_on_attach.c
** File description:
** layer_level_on_attach.c
*/

#include "entities/skeleton_impl.h"
#include "layers/level_impl.h"
#include "entities/skeleton.h"
#include "entities/player.h"
#include "entities/npc.h"

static bool create_music(level_t *level)
{
    level->music = sfMusic_createFromFile("res/sounds/main_theme.ogg");
    if (level->music == NULL)
        return false;
    sfMusic_setLoop(level->music, sfTrue);
    sfMusic_play(level->music);
    sfMusic_setVolume(level->music, 25);
    return true;
}

static bool add_npc(layer_t *layer, level_t *level, const char *str,
    sfVector2f pos)
{
    entity_t *npc = entity_npc_new(level->player, str, pos);

    if (npc == NULL)
        return false;
    return layer_add_entity(layer, npc);
}

static bool add_npcs(layer_t *layer, level_t *level)
{
    if (!add_npc(layer, level, "Your quest is to bring me all the potions!",
        (sfVector2f){150, 775}))
        return false;
    if (!add_npc(layer, level,"Press Z,Q,S,D to move the player",
        (sfVector2f){20, 675}))
        return false;
    if (!add_npc(layer, level,"Press arrows to move the camera and space"
        " to recenter", (sfVector2f){150, 660}))
        return false;
    if (!add_npc(layer, level,"Press left click to cast fireball"
        ,(sfVector2f){300, 760}))
        return false;
    return true;
}

static bool add_skeletons(layer_t *layer, level_t *level)
{
    return add_skeleton(layer, (sfVector2f){610, 730})
        && add_skeleton(layer, (sfVector2f){500, 300})
        && add_skeleton(layer, (sfVector2f){550, 380})
        && add_skeleton(layer, (sfVector2f){350, 80})
        && add_skeleton(layer, (sfVector2f){350, 200})
        && add_skeleton(layer, (sfVector2f){550, 80})
        && add_skeleton(layer, (sfVector2f){750, 150})
        && add_skeleton(layer, (sfVector2f){550, 250})
        && add_skeleton(layer, (sfVector2f){700, 230})
        && add_skeleton(layer, (sfVector2f){610, 750});
}

bool layer_level_on_attach(layer_t *layer)
{
    level_t *level = layer_get_data(layer);

    level->player = player_new();
    if (level->player == NULL || !layer_add_entity(layer, level->player))
        return false;
    return add_npcs(layer, level) && add_skeletons(layer, level)
        && create_music(level);
}
