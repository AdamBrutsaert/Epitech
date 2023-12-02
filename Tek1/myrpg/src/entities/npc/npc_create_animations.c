/*
** EPITECH PROJECT, 2023
** npc_create_animations.c
** File description:
** npc_create_animations.c
*/

#include "entities/npc_impl.h"

static bool create_npc_animation(entity_npc_t *npc)
{
    npc->idle_animation = animation_new();
    if (!npc->idle_animation)
        return false;
    for (int i = 0; i < 4; i++)
        animation_add_frame(
            npc->idle_animation,
            (sfIntRect){i * 16, 0, 16, 20}
        );
    animation_set_speed(npc->idle_animation, 3.0f);
    return true;
}

bool npc_create_animations(entity_t *entity)
{
    entity_npc_t *npc = entity_get_data(entity);

    return create_npc_animation(npc);
}
