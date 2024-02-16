/*
** EPITECH PROJECT, 2023
** layer.h
** File description:
** layer.h
*/

#pragma once

#include "entity.h"

typedef struct layer layer_t;

struct engine;

typedef bool (*layer_on_attach_t)(layer_t *layer);
typedef void (*layer_on_detach_t)(layer_t *layer);
typedef bool (*layer_on_event_t)(layer_t *layer, sfEvent *event);
typedef bool (*layer_on_update_t)(layer_t *layer, float dt);
typedef void (*layer_on_render_t)(layer_t *layer);

/**
 * @brief Allocate a new layer
 *
 * @param data_size size of the layer's data
 * @return layer_t* the new layer
 */
layer_t *layer_new(size_t data_size);

/**
 * @brief Free a layer
 *
 * @param layer the layer to free
 */
void layer_delete(layer_t *layer);

/**
 * @brief Bind a function to be called when the layer is added
 *
 * @param layer the layer
 * @param on_attach the function to call
 */
void layer_bind_on_attach(layer_t *layer, layer_on_attach_t on_attach);

/**
 * @brief Bind a function to be called when the layer is removed
 *
 * @param layer the layer
 * @param on_detach the function to call
 */
void layer_bind_on_detach(layer_t *layer, layer_on_detach_t on_detach);

/**
 * @brief Bind a function to be called when an event is received
 *
 * @param layer the layer
 * @param on_event the function to call
 */
void layer_bind_on_event(layer_t *layer, layer_on_event_t on_event);

/**
 * @brief Bind a function to be called when the layer is updated
 *
 * @param layer the layer
 * @param on_update the function to call
 */
void layer_bind_on_update(layer_t *layer, layer_on_update_t on_update);

/**
 * @brief Bind a function to be called when the layer is rendered
 *
 * @param layer the layer
 * @param on_render the function to call
 */
void layer_bind_on_render(layer_t *layer, layer_on_render_t on_render);

/**
 * @brief Set the engine
 *
 * @param layer the layer
 * @param engine the engine
 */
void layer_set_engine(layer_t *layer, struct engine *engine);

/**
 * @brief Call the on_attach function
 *
 * @param layer the layer
 * @return true if the function returned true
 * @return false if the function returned false
 */
bool layer_on_attach(layer_t *layer);

/**
 * @brief Call the on_detach function
 *
 * @param layer the layer
 */
void layer_on_detach(layer_t *layer);

/**
 * @brief Send event to entities and call the on_event function
 *
 * @param layer the layer
 * @param event the event
 * @return true if no error occured
 * @return false if an error occured
 */
bool layer_on_event(layer_t *layer, sfEvent *event);

/**
 * @brief Update the layer and call the on_update function
 *
 * @param layer the layer
 * @param dt the time elapsed since the last update
 * @return true if the function returned true
 * @return false if the function returned false
 */
bool layer_on_update(layer_t *layer, float dt);

/**
 * @brief Render the layer
 *
 * @param layer the layer
 */
void layer_on_render(layer_t *layer);

/**
 * @brief Render the hitboxes of the layer
 *
 * @param layer the layer
 */
void layer_render_hitboxes(layer_t *layer);

/**
 * @brief Get the data
 *
 * @param layer the layer
 * @return void* the data
 */
void *layer_get_data(layer_t *layer);

/**
 * @brief Get the engine
 *
 * @param layer the layer
 * @return struct engine* the engine
 */
struct engine *layer_get_engine(layer_t *layer);

/**
 * @brief Get the window
 *
 * @param layer the layer
 * @return sfRenderWindow* the window
 */
sfRenderWindow *layer_get_window(layer_t *layer);

/**
 * @brief Add an entity to the layer
 *
 * @param layer the layer
 * @param entity the entity to add
 * @return true if the entity was added
 * @return false if the entity was not added
 */
bool layer_add_entity(layer_t *layer, entity_t *entity);

/**
 * @brief Remove an entity from the layer
 *
 * @param layer the layer
 * @param entity the entity to remove
 */
void layer_remove_entity(layer_t *layer, entity_t *entity);

/**
 * @brief Check if the layer is colliding with a hitbox
 *
 * @param layer the layer
 * @param entity_t* the entity
 * @return entity_t* the entity that is colliding
 * @return NULL if no entity is colliding
 */
entity_t *layer_is_colliding(layer_t *layer, entity_t *entity);

/**
 * @brief Get the render states
 *
 * @param layer the layer
 * @return sfRenderStates* the states
 */
sfRenderStates *layer_get_render_states(layer_t *layer);

/**
 * @brief Get the view
 *
 * @param layer the layer
 * @return sfView* the view
 */
sfView *layer_get_view(layer_t *layer);
