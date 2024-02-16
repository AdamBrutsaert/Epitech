/*
** EPITECH PROJECT, 2023
** player_level_up.c
** File description:
** player_level_up.c
*/

#include "entities/player_impl.h"
#include "save.h"

void give_item(player_t *player)
{
    item_t *item;

    if (player->level == 1 && player->xp == 1 && !STATE.has_red_pot) {
        item = item_new(ITEM_FLASK_RED);
        if (!item)
            return;
        STATE.has_red_pot = true;
        sfSound_play(player->flask_sound);
        inventory_add_item(player->inventory, item);
    }
    if (player->level == 4 && player->xp == 0 && !STATE.has_blue_pot) {
        item = item_new(ITEM_FLASK_YELLOW);
        if (!item)
            return;
        STATE.has_blue_pot = true;
        sfSound_play(player->flask_sound);
        inventory_add_item(player->inventory, item);
    }
}

void player_level_up(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    player->xp += 1;
    if (player->xp >= player->level + 1 && player->level < 8) {
        sfSound_play(player->lvlup_sound);
        player->xp = 0;
        player->level += 1;
        player->strength += 1;
        if (player->strength > 8)
            player->strength = 8;
    }
    give_item(player);
}
