/*
** EPITECH PROJECT, 2023
** entity_get_layer.c
** File description:
** entity_get_layer.c
*/

#include "engine/entity_impl.h"

layer_t *entity_get_layer(entity_t *entity)
{
    return entity->layer;
}
