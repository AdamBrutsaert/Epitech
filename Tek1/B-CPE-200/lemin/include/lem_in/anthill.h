/*
** EPITECH PROJECT, 2023
** anthill.h
** File description:
** anthill.h
*/

#pragma once

#include <stdbool.h>

#include "room.h"

typedef struct anthill anthill_t;

/**
 * @brief Allocate a new anthill
 *
 * @return anthill_t* the anthill
 */
anthill_t *anthill_new(void);

/**
 * @brief Free an anthill
 *
 * @param anthill the anthill
 */
void anthill_delete(anthill_t *anthill);

/**
 * @brief Set the ant count
 *
 * @param anthill the anthill
 * @param ant_count the ant count
 */
void anthill_set_ant_count(anthill_t *anthill, size_t ant_count);

/**
 * @brief Get the ant count
 *
 * @param anthill the anthill
 * @return size_t the ant count
 */
size_t anthill_get_ant_count(anthill_t *anthill);

/**
 * @brief Add a room to the anthill
 *
 * @param anthill the anthill
 * @param room the room
 * @return true if the room was added
 * @return false if the room was not added
 */
bool anthill_add_room(anthill_t *anthill, room_t *room);

/**
 * @brief Set the start room of the anthill
 *
 * @param anthill the anthill
 * @param name the start room's name
 * @return true if the start room was set
 * @return false if the start room was not set
 */
bool anthill_set_start(anthill_t *anthill, const char *name);

/**
 * @brief Set the end room of the anthill
 *
 * @param anthill the anthill
 * @param name the end room's name
 * @return true if the end room was set
 * @return false if the end room was not set
 */
bool anthill_set_end(anthill_t *anthill, const char *name);

/**
 * @brief Get the start room of the anthill
 *
 * @param anthill the anthill
 * @return room_t* the start room
 */
room_t *anthill_get_start(anthill_t *anthill);

/**
 * @brief Get the end room of the anthill
 *
 * @param anthill the anthill
 * @return room_t* the end room
 */
room_t *anthill_get_end(anthill_t *anthill);

/**
 * @brief Get the room from its id
 *
 * @param anthill the anthill
 * @param id the room id
 * @return room_t* the room
 */
room_t *anthill_get_room_from_id(anthill_t *anthill, size_t id);

/**
 * @brief Get the length
 *
 * @param anthill the anthill
 * @return size_t the length
 */
size_t anthill_get_length(anthill_t *anthill);

/**
 * @brief Add a tunnel between two rooms
 *
 * @param anthill the anthill
 * @param name1 the first room's name
 * @param name2 the second room's name
 * @return true if the tunnel was added
 * @return false if the tunnel was not added
 */
bool anthill_add_tunnel(
    anthill_t *anthill,
    const char *name1,
    const char *name2
);

/**
 * @brief Check if two rooms are connected
 *
 * @param anthill the anthill
 * @param id1 the first room id
 * @param id2 the second room id
 * @return true if the rooms are connected
 * @return false if the rooms are not connected
 */
bool anthill_is_connected(anthill_t *anthill, size_t id1, size_t id2);

/**
 * @brief Print the anthill
 *
 * @param anthill the anthill
 */
void anthill_print(anthill_t *anthill);

/**
 * @brief Check if the anthill is valid
 *
 * @param anthill the anthill
 * @return true if the anthill is valid
 * @return false if the anthill is not valid
 */
bool anthill_is_valid(anthill_t *anthill);
