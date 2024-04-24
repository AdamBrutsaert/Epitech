/*
** EPITECH PROJECT, 2024
** reader.h
** File description:
** reader.h
*/

#pragma once

#include "token.h"

/*********************************** Types ***********************************/

/// Represents a reader
typedef struct {
    vec_t *buffer;
    size_t cursor;
} reader_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a reader
reader_t *reader_create(void);

/// Destroys a reader
void reader_destroy(reader_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes some bytes from stdin
bool reader_push_stdin(reader_t *self);

/// Checks if the reader contains a newline after the cursor
bool reader_contains_newline(reader_t *self);

/// Peek next character
char reader_peek(reader_t *self);

/// Pop next character
char reader_pop(reader_t *self);

/// Clears the buffer up to the cursor
void reader_clear_up_to_cursor(reader_t *self);

/// Clears the buffer up to the newline
void reader_clear_up_to_newline(reader_t *self);

/// Get last n characters
string_t *reader_get_last_characters(reader_t *self, size_t n);

/// Gets the next token
bool reader_lex(reader_t *reader, token_t **token);

/*****************************************************************************/
