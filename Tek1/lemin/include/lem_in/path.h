/*
** EPITECH PROJECT, 2023
** path.h
** File description:
** path.h
*/

#pragma once

#include "room.h"

typedef struct path path_t;

/**
 * @brief Allocate a new path
 *
 * @return path_t* the path
 */
path_t *path_new(void);

/**
 * @brief Free a path
 *
 * @param path the path
 */
void path_delete(path_t *path);

/**
 * @brief Get the length of the path
 *
 * @param path the path
 *
 * @return size_t the length
 */
size_t path_get_length(path_t *path);

/**
 * @brief Get the room at the given index
 *
 * @param path the path
 * @param index the index
 *
 * @return room_t* the room
 */
room_t *path_get_room(path_t *path, size_t index);

/**
 * @brief Add a room to the path
 *
 * @param path the path
 * @param room the room
 */
bool path_add_room(path_t *path, room_t *room);

/**
 * @brief Reverse the path
 *
 * @param path the path
 */
void path_reverse(path_t *path);

size_t path_get_cost(path_t *path);
void path_add_ant(path_t *path);
bool path_advance(path_t *path, bool *print_space);
