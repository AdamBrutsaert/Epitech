/*
** EPITECH PROJECT, 2023
** entity.h
** File description:
** entity.h
*/

#pragma once

#include <stddef.h>
#include <stdbool.h>
#include <sys/types.h>

#include <SFML/Graphics.h>

#define ENTITY_UNKNOWN_TYPE "__Entity_Unknown_Type__"

typedef struct entity entity_t;

typedef bool (*entity_on_attach_t)(entity_t *entity);
typedef void (*entity_on_detach_t)(entity_t *entity);
typedef bool (*entity_on_event_t)(entity_t *entity, sfEvent *event);
typedef bool (*entity_on_update_t)(entity_t *entity, float dt);
typedef void (*entity_on_render_t)(entity_t *entity);

struct layer;
struct engine;

/**
 * @brief Allocate a new entity
 *
 * @param data_size size of the entity's data
 * @return entity_t* the new entity
 */
entity_t *entity_new(size_t data_size);

/**
 * @brief Free an entity
 *
 * @param entity the entity to free
 */
void entity_delete(entity_t *entity);

/**
 * @brief Set the layer of an entity
 *
 * @param entity the entity
 * @param layer the layer
 */
void entity_set_layer(entity_t *entity, struct layer *layer);

/**
 * @brief Bind a function to be called when the entity is added
 *
 * @param entity the entity
 * @param on_attach the function to call
 */
void entity_bind_on_attach(entity_t *entity, entity_on_attach_t on_attach);

/**
 * @brief Bind a function to be called when the entity is removed
 *
 * @param entity the entity
 * @param on_detach the function to call
 */
void entity_bind_on_detach(entity_t *entity, entity_on_detach_t on_detach);

/**
 * @brief Bind a function to be called when an event is received
 *
 * @param entity the entity
 * @param on_event the function to call
 */
void entity_bind_on_event(entity_t *entity, entity_on_event_t on_event);

/**
 * @brief Bind a function to be called when the entity is updated
 *
 * @param entity the entity
 * @param on_update the function to call
 */
void entity_bind_on_update(entity_t *entity, entity_on_update_t on_update);

/**
 * @brief Bind a function to be called when the entity is rendered
 *
 * @param entity the entity
 * @param on_render the function to call
 */
void entity_bind_on_render(entity_t *entity, entity_on_render_t on_render);

/**
 * @brief Call the on_attach function
 *
 * @param entity the entity
 * @return true if the function returned true
 * @return false if the function returned false
 */
bool entity_on_attach(entity_t *entity);

/**
 * @brief Call the on_detach function
 *
 * @param entity the entity
 */
void entity_on_detach(entity_t *entity);

/**
 * @brief Call the on_event function
 *
 * @param entity the entity
 * @param event the event
 * @return true if the function returned true
 * @return false if the function returned false
 */
bool entity_on_event(entity_t *entity, sfEvent *event);

/**
 * @brief Call the on_update function
 *
 * @param entity the entitty
 * @param dt the time since the last update
 * @return true if the function returned true
 * @return false if the function returned false
 */
bool entity_on_update(entity_t *entity, float dt);

/**
 * @brief Call the on_render function
 *
 * @param entity the entity
 */
void entity_on_render(entity_t *entity);

/**
 * @brief Render the hitboxes of an entity
 *
 * @param entity the entity
 */
void entity_render_hitboxes(entity_t *entity);

/**
 * @brief Get the data of an entity
 *
 * @param entity the entity
 * @return void* the data
 */
void *entity_get_data(entity_t *entity);

/**
 * @brief Get the layer of an entity
 *
 * @param entity then entity
 * @return void* the layer
 */
struct layer *entity_get_layer(entity_t *entity);

/**
 * @brief Get the engine
 *
 * @param entity the entity
 * @return struct engine* the engine
 */
struct engine *entity_get_engine(entity_t *entity);

/**
 * @brief Get the window
 *
 * @param entity the entity
 * @return sfRenderWindow* the window
 */
sfRenderWindow *entity_get_window(entity_t *entity);

/**
 * @brief Set the tpye of an entity
 *
 * @param entity the entity
 * @param type the type
 */
void entity_set_type(entity_t *entity, const char *type);

/**
 * @brief Get the type of an entity
 *
 * @param entity the entity
 * @return const char* the type
 */
const char *entity_get_type(entity_t *entity);

/**
 * @brief Add a new hitbox
 *
 * @param entity the entity
 * @param hitbox the hitbox
 * @return ssize_t the id of the hitbox
 * @return -1 if an error occured
 */
ssize_t entity_add_hitbox(entity_t *entity, sfFloatRect hitbox);

/**
 * @brief Get a hitbox
 *
 * @param entity the entity
 * @param id the id
 * @return sfFloatRect the hitbox
 */
sfFloatRect *entity_get_hitbox(entity_t *entity, ssize_t id);

/**
 * @brief Remove a hitbox
 *
 * @param entity the entity
 * @param id the id
 */
void entity_remove_hitbox(entity_t *entity, ssize_t id);

/**
 * @brief Check if an entity is colliding with a hitbox
 *
 * @param entity the entity
 * @param other the other entity
 * @return true if the entity is colliding
 * @return false if the entity is not colliding
 */
bool entity_is_colliding(entity_t *entity, entity_t *other);

/**
 * @brief Get the render states
 *
 * @param entity the entity
 * @return sfRenderStates* the states
 */
sfRenderStates *entity_get_render_states(entity_t *entity);
