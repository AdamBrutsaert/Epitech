/*
** EPITECH PROJECT, 2024
** token.h
** File description:
** token.h
*/

#pragma once

#include "my/memory/string.h"

/*********************************** Types ***********************************/

typedef enum : uint8_t {
    TOKEN_TYPE_INVALID = 255,
    TOKEN_TYPE_STRING = 0,
    TOKEN_TYPE_ARGUMENT,
    TOKEN_TYPE_SLASH,
    TOKEN_TYPE_NEWLINE,
} token_type_t;

typedef struct {
    token_type_t type;
    string_t *value;
} token_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a token
token_t *token_create(token_type_t type, const string_t *value);

/// Destroys a token
void token_destroy(token_t *self);

/*****************************************************************************/
