/*
** EPITECH PROJECT, 2023
** entity_set_layer.c
** File description:
** entity_set_layer.c
*/

#include "engine/entity_impl.h"

void entity_set_layer(entity_t *entity, struct layer *layer)
{
    entity->layer = layer;
}
