/*
** EPITECH PROJECT, 2023
** engine_is_colliding.c
** File description:
** engine_is_colliding.c
*/

#include "engine_impl.h"

entity_t *engine_is_colliding(engine_t *engine, entity_t *entity)
{
    entity_t *other;

    for (size_t i = engine->layers_length; i != 0; i--) {
        other = layer_is_colliding(engine->layers[i - 1], entity);
        if (other != NULL)
            return other;
    }
    return NULL;
}
