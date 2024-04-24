/*
** EPITECH PROJECT, 2024
** auth.h
** File description:
** auth.h
*/

#pragma once

#include <stdbool.h>

/****************************** Data structures ******************************/

/// Represents an user
typedef struct {
    char *name;
    bool authed;
} user_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the user
void user_init(user_t *self);

/// Deinitializes the user
void user_deinit(user_t *self);

/*****************************************************************************/

/***************************** Getters & Setters *****************************/

/// Returns the name of the user
const char *user_name(user_t *self);

/// Returns whether it is authed
bool user_is_authed(user_t *self);

/// Sets the name of the auth
bool user_set_name(user_t *self, const char *name);

/// Tries to authenticate the user
void user_authenticate(user_t *self, const char *password);

/*****************************************************************************/
