/*
** EPITECH PROJECT, 2023
** entity_get_window.c
** File description:
** entity_get_window.c
*/

#include "engine/entity_impl.h"
#include "engine.h"

sfRenderWindow *entity_get_window(entity_t *entity)
{
    return engine_get_window(layer_get_engine(entity->layer));
}
