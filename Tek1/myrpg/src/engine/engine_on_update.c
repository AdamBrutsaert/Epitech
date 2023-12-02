/*
** EPITECH PROJECT, 2023
** engine_on_update.c
** File description:
** engine_on_update.c
*/

#include "engine_impl.h"

bool engine_on_update(engine_t *engine, float dt)
{
    for (size_t i = engine->layers_length; i != 0; i--) {
        if (!layer_on_update(engine->layers[i - 1], dt))
            return false;
    }
    return true;
}
