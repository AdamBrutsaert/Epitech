/*
** EPITECH PROJECT, 2023
** engine_impl.h
** File description:
** engine_impl.h
*/

#pragma once

#include "engine.h"

typedef struct {
    enum { EVENT_PUSH, EVENT_POP, EVENT_REMOVE, EVENT_CLEAR } type;
    layer_t *layer;
} event_t;

struct engine {
    sfRenderWindow *window;
    bool fullscreen;

    event_t *events;
    size_t events_length;
    size_t events_capacity;
    bool prevent_propagation;

    layer_t **layers;
    size_t layers_length;
    size_t layers_capacity;

    bool show_hitboxes;
    sfRenderStates states;
};

/**
 * @brief Push an event
 *
 * @param engine the engine
 * @param event the event
 * @return true if the event was pushed
 * @return false if the event was not pushed
 */
bool engine_push_event(engine_t *engine, event_t *event);

/**
 * @brief Handle layer events
 *
 * @param engine the engine
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_handle_layer_events(engine_t *engine);

/**
 * @brief Handle events
 *
 * @param engine the engine
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_handle_events(engine_t *engine);

/**
 * @brief Update the layers
 *
 * @param engine the engine
 * @param dt the delta time
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_on_update(engine_t *engine, float dt);

/**
 * @brief Render the layers
 *
 * @param engine the engine
 */
void engine_on_render(engine_t *engine);
