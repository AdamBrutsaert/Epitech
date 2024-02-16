/*
** EPITECH PROJECT, 2023
** engine_pop_layer.c
** File description:
** engine_pop_layer.c
*/

#include "engine_impl.h"

bool engine_pop_layer(engine_t *engine)
{
    event_t event = { .type = EVENT_POP, .layer = NULL };

    return engine_push_event(engine, &event);
}
