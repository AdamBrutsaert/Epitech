/*
** EPITECH PROJECT, 2023
** npc_impl.h
** File description:
** npc_impl.h
*/

#pragma once

#include "npc.h"
#include "utils/animation.h"

#include <SFML/Audio.h>

typedef struct {
    const char *string;
    sfVector2f position;
    sfTexture *texture;
    sfSprite *sprite;
    entity_t *player_entity;
    animation_t *idle_animation;
    animation_t *walk_animation;
    sfFont *font;
    sfText *text;
    bool show_text;

    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    bool has_played;
} entity_npc_t;

bool entity_npc_on_attach(entity_t *entity);
void entity_npc_on_detach(entity_t *entity);
bool entity_npc_on_event(entity_t *entity, sfEvent *event);
bool entity_npc_on_update(entity_t *entity, float dt);
void entity_npc_on_render(entity_t *entity);

bool npc_create_animations(entity_t *entity);
