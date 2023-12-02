/*
** EPITECH PROJECT, 2023
** player_on_attach.c
** File description:
** player_on_attach.c
*/

#include "entities/player_impl.h"
#include "save.h"

static bool create_textures(player_t *player)
{
    player->texture = sfTexture_createFromFile("res/wizard.png", NULL);
    player->weapon_texture = sfTexture_createFromFile(
        "res/magic_staff.png",
        NULL
    );
    return player->texture && player->weapon_texture;
}

static bool create_camera(entity_t *entity, player_t *player)
{
    sfVector2u size = sfRenderWindow_getSize(entity_get_window(entity));
    sfVector2f pos = sfSprite_getPosition(player->sprite);

    player->camera = camera_new();
    if (!player->camera)
        return false;
    camera_set_size(player->camera, (sfVector2f){size.x, size.y});
    camera_teleport(player->camera, (sfVector2f){pos.x + 8, pos.y + 14});
    return true;
}

static bool set_hitbox(entity_t *entity, player_t *player)
{
    sfVector2f position = sfSprite_getPosition(player->sprite);

    entity_set_type(entity, "Player");
    return entity_add_hitbox(entity, (sfFloatRect) {
        position.x,
        position.y + 16,
        16,
        12
    }) != -1;
}

static bool load_save(player_t *player)
{
    item_t *item;

    if (STATE.has_red_pot) {
        item = item_new(ITEM_FLASK_RED);
        if (!item)
            return false;
        inventory_add_item(player->inventory, item);
    }
    if (STATE.has_blue_pot) {
        item = item_new(ITEM_FLASK_YELLOW);
        if (!item)
            return false;
        inventory_add_item(player->inventory, item);
    }
    return true;
}

bool player_on_attach(entity_t *entity)
{
    player_t *player = entity_get_data(entity);

    player->inventory = inventory_new(PLAYER_INVENTORY_SIZE);
    player->sprite = sfSprite_create();
    player->weapon = sfSprite_create();
    if (player->sprite == NULL || player->weapon == NULL
        || player->inventory == NULL || !create_textures(player)
        || !player_create_animations(entity))
        return false;
    player->life = 3;
    player->max_life = 3;
    player->strength = 1;
    sfSprite_setTexture(player->sprite, player->texture, sfTrue);
    sfSprite_setTexture(player->weapon, player->weapon_texture, sfTrue);
    sfSprite_setOrigin(player->weapon, (sfVector2f){4, 20});
    sfSprite_setPosition(player->sprite, (sfVector2f){32,735});
    load_save(player);
    return create_camera(entity, player) && set_hitbox(entity, player)
        && player_create_sounds(player);
}
