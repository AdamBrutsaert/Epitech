/*
** EPITECH PROJECT, 2023
** engine_clear_layers.c
** File description:
** engine_clear_layers.c
*/

#include "engine_impl.h"

bool engine_clear_layers(engine_t *engine)
{
    event_t event = { .type = EVENT_CLEAR, .layer = NULL };

    return engine_push_event(engine, &event);
}
