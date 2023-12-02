/*
** EPITECH PROJECT, 2023
** room.h
** File description:
** room.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct room room_t;

/**
 * @brief Allocate a new room
 *
 * @return room_t* the room
 */
room_t *room_new(void);

/**
 * @brief Free a room
 *
 * @param room the room
 */
void room_delete(room_t *room);

/**
 * @brief Set the name
 *
 * @param room the room
 * @param name the name
 *
 * @warning the name will be freed
 */
void room_set_name(room_t *room, char *name);

/**
 * @brief Set the x coordinate
 *
 * @param room the room
 * @param x the x coordinate
 */
void room_set_x(room_t *room, int32_t x);

/**
 * @brief Set the y coordinate
 *
 * @param room the room
 * @param y the y coordinate
 */
void room_set_y(room_t *room, int32_t y);

/**
 * @brief Set the room as visited or not
 *
 * @param room the room
 * @param status whether the room is visited or not
 */
void room_set_visited(room_t *room, bool status);

/**
 * @brief Get the id
 *
 * @param room the room
 * @return size_t the id
 */
size_t room_get_id(room_t *room);

/**
 * @brief Get the name
 *
 * @param room the room
 * @return char* the name
 */
char *room_get_name(room_t *room);

/**
 * @brief Get the x coordinate
 *
 * @param room the room
 * @return int32_t the x coordinate
 */
int32_t room_get_x(room_t *room);

/**
 * @brief Get the y coordinate
 *
 * @param room the room
 * @return int32_t the y coordinate
 */
int32_t room_get_y(room_t *room);

/**
 * @brief Check if the room is visited
 *
 * @param room the room
 * @return true if the room is visited
 * @return false if the room is not visited
 */
bool room_is_visited(room_t *room);

/**
 * @brief Set the previous id
 *
 * @param room the room
 * @param id the previous id
 */
void room_set_previous_id(room_t *room, size_t id);

/**
 * @brief Get the previous id
 *
 * @param room the room
 * @return size_t the previous id
 */
size_t room_get_previous_id(room_t *room);
