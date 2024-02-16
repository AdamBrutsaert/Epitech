/*
** EPITECH PROJECT, 2023
** engine.h
** File description:
** engine.h
*/

#pragma once

#include "engine/layer.h"

#include <SFML/Graphics.h>
#include <stdint.h>

#define RES(path) ("res/"path)

typedef struct engine engine_t;

/**
 * @brief Allocate a new engine
 *
 * @param width the width of the window
 * @param height the height of the window
 * @param title the title of the window
 * @return engine_t* the new engine
 */
engine_t *engine_new(uint32_t width, uint32_t height, const char *title);

/**
 * @brief Free an engine
 *
 * @param engine the engine
 */
void engine_delete(engine_t *engine);

/**
 * @brief Run the engine
 *
 * @param engine the engine
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_run(engine_t *engine);

/**
 * @brief Get the window
 *
 * @param engine the engine
 * @return sfRenderWindow* the window
 */
sfRenderWindow *engine_get_window(engine_t *engine);

/**
 * @brief Push a layer
 *
 * @param engine the engine
 * @param layer the layer
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_push_layer(engine_t *engine, layer_t *layer);

/**
 * @brief Pop a layer
 *
 * @param engine the engine
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_pop_layer(engine_t *engine);

/**
 * @brief Remove a layer
 *
 * @param engine the engine
 * @param layer the layer
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_remove_layer(engine_t *engine, layer_t *layer);

/**
 * @brief Clear the layers
 *
 * @param engine the engine
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_clear_layers(engine_t *engine);

/**
 * @brief Check if a hitbox is colliding with something
 *
 * @param engine the engine
 * @param entity_t* the entity
 * @return entity_t* the entity that is colliding
 * @return NULL if the hitbox is not colliding
 */
entity_t *engine_is_colliding(engine_t *engine, entity_t *entity);

/**
 * @brief Whether it should show the hitboxes
 *
 * @param engine the engine
 * @return true if the hitboxes are shown
 * @return false if the hitboxes are not shown
 */
bool engine_should_show_hitboxes(engine_t *engine);

/**
 * @brief Get the render states
 *
 * @param engine the engine
 * @return sfRenderStates* the render states
 */
sfRenderStates *engine_get_render_states(engine_t *engine);

/**
 * @brief Set fullscreen
 *
 * @param engine the engine
 * @param fullscreen whether the window should be fullscreen
 * @return true if no error occured
 * @return false if an error occured
 */
bool engine_set_fullscreen(engine_t *engine, bool fullscreen);

/**
 * @brief Check if the window is fullscreen
 *
 * @param engine the engine
 * @return true if the window is fullscreen
*/
bool engine_is_fullscreen(engine_t *engine);

/**
 * @brief Prevent the propagation of the current event
 *
 * @param engine the engine
 */
void engine_prevent_propagation(engine_t *engine);

/**
 * @brief Whether the propagation of the current event should be prevented
 *
 * @param engine the engine
 * @return true if the propagation should be prevented
 * @return false if the propagation should not be prevented
 */
bool engine_should_prevent_propagation(engine_t *engine);
