/*
** EPITECH PROJECT, 2023
** lem_in_impl.h
** File description:
** lem_in_impl.h
*/

#pragma once

#include "lem_in.h"
#include "lem_in/queue.h"
#include "lem_in/path.h"

typedef struct {
    anthill_t *anthill;
    queue_t *queue;
    path_t **paths;
    size_t length;
    size_t capacity;
} lem_in_t;

/**
 * @brief Clear the lem_in
 *
 * @param lem_in the lem_in
 */
void lem_in_clear(lem_in_t *lem_in);

/**
 * @brief Add a path to the lem_in
 *
 * @param lem_in the lem_in
 * @param path the path
 * @return true if the path was added
 * @return false if the path was not added
 */
bool lem_in_add_path(lem_in_t *lem_in, path_t *path);

/**
 * @brief Find all the paths in the anthill
 *
 * @param anthill the anthill
 * @return path_t** the paths
 */
bool lem_in_find_paths(lem_in_t *lem_in);

bool lem_in_path_intersect(lem_in_t *lem_in, path_t *path);

void lem_in_dispatch_ants(lem_in_t *lem_in);
void lem_in_advance(lem_in_t *lem_in);
