/*
** EPITECH PROJECT, 2024
** parsing.h
** File description:
** parsing.h
*/

#pragma once

#include "reader.h"

/*********************************** Types ***********************************/

/// Represents a command
typedef struct {
    string_t *name;
    vec_t *arguments;
} command_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a command
command_t *command_create(void);

/// Destroys a command
void command_destroy(command_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Parses a command
bool command_parse(command_t *self, reader_t *reader);

/*****************************************************************************/
