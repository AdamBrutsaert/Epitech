/*
** EPITECH PROJECT, 2023
** entity_npc_on_update.c
** File description:
** entity_npc_on_update.c
*/

#include <math.h>

#include "entities/npc_impl.h"
#include "entities/player_impl.h"
#include "utils/animation.h"

static bool is_near_player(entity_npc_t *npc)
{
    player_t *player = entity_get_data(npc->player_entity);
    sfVector2f player_pos = sfSprite_getPosition(player->sprite);
    sfVector2f npc_pos = sfSprite_getPosition(npc->sprite);

    if (fabs(player_pos.x - npc_pos.x) < NPC_TRIGGER_DISTANCE
        && fabs(player_pos.y - npc_pos.y) < NPC_TRIGGER_DISTANCE) {
        if (!npc->has_played) {
            sfSound_play(npc->sound);
            npc->has_played = true;
        }
        return true;
    } else {
        npc->has_played = false;
    }
    return false;
}

bool entity_npc_on_update(entity_t *entity, float dt)
{
    entity_npc_t *npc = entity_get_data(entity);
    sfIntRect *rect;

    rect = animation_update(npc->idle_animation, dt);
    if (rect == NULL)
        return false;
    sfSprite_setTextureRect(npc->sprite, *rect);
    npc->show_text = is_near_player(npc);
    return true;
}
