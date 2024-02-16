/*
** EPITECH PROJECT, 2023
** anthill_impl.h
** File description:
** anthill_impl.h
*/

#pragma once

#include "anthill.h"
#include "matrix.h"

#define ROOMS_HASHMAP_SIZE 64

typedef struct room_node {
    room_t *room;
    struct room_node *next;
} room_node_t;

struct anthill {
    room_node_t **rooms;
    matrix_t *matrix;
    room_t *start;
    room_t *end;
    size_t length;
    size_t ant_count;
};

/**
 * @brief Get a room node from the anthill
 *
 * @param anthill the anthill
 * @param name the room's name
 * @return room_node_t* the room node
 */
room_node_t *anthill_get_room_node(anthill_t *anthill, const char *name);

room_t *anthill_get_room_from_coordinates(
    anthill_t *anthill,
    int32_t x,
    int32_t y
);
