/*
** EPITECH PROJECT, 2023
** entity_get_engine.c
** File description:
** entity_get_engine.c
*/

#include "engine/entity_impl.h"

struct engine *entity_get_engine(entity_t *entity)
{
    return layer_get_engine(entity->layer);
}
