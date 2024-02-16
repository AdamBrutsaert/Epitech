/*
** EPITECH PROJECT, 2023
** engine_push_event.c
** File description:
** engine_push_event.c
*/

#include "engine_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(engine_t *engine)
{
    size_t capacity = engine->events_capacity * 2 + !engine->events_capacity;
    event_t *events = malloc(sizeof(event_t) * capacity);

    if (events == NULL)
        return false;
    my_memcpy(events, engine->events, sizeof(event_t) * engine->events_length);
    free(engine->events);
    engine->events = events;
    engine->events_capacity = capacity;
    return true;
}

bool engine_push_event(engine_t *engine, event_t *event)
{
    if (engine->events_length == engine->events_capacity && !grow(engine))
        return false;
    engine->events[engine->events_length].type = event->type;
    engine->events[engine->events_length].layer = event->layer;
    engine->events_length++;
    return true;
}
