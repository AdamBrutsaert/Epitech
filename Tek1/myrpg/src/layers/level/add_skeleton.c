/*
** EPITECH PROJECT, 2023
** add_skeleton.c
** File description:
** add_skeleton.c
*/

#include "layers/level_impl.h"
#include "entities/skeleton_impl.h"

bool add_skeleton(layer_t *layer, sfVector2f pos)
{
    level_t *level = layer_get_data(layer);
    entity_t *skeleton = entity_skeleton_new(pos);
    entity_skeleton_t *skeleton_data;

    if (skeleton == NULL)
        return false;
    skeleton_data = entity_get_data(skeleton);
    skeleton_data->player = level->player;
    return layer_add_entity(layer, skeleton);
}
