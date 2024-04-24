/*
** EPITECH PROJECT, 2024
** path.h
** File description:
** path.h
*/

#pragma once

#include <stdbool.h>

/****************************** Data structures ******************************/

/// Represents a path
typedef struct {
    char *root;
    char *path;
} path_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the path
bool path_init(path_t *self, const char *root);

/// Initializes the path from another path
bool path_init_copy(path_t *self, const path_t *other);

/// Deinitializes the path
void path_deinit(path_t *self);

/*****************************************************************************/

/********************************** Getters **********************************/

/// Returns the path
const char *path_get(path_t *self);

/*****************************************************************************/

/********************************** Setters **********************************/

/// Changes the path up one level
void path_change_up(path_t *self);

/// Changes the path to an absolute path if it exists
bool path_change_absolute(path_t *self, const char *path);

/// Changes the path to a relative directory if it exists
bool path_change_directory(path_t *self, const char *directory);

/// Changes the path to a relative path if it exists
bool path_change_relative(path_t *self, const char *path);

/// Changes the path either relative or absolute if it exists
bool path_change(path_t *self, const char *path);

/*****************************************************************************/
