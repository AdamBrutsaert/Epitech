/*
** EPITECH PROJECT, 2023
** redirection.h
** File description:
** redirection.h
*/

#pragma once

typedef struct redirection redirection_t;

typedef enum {
    REDIRECTION_OUTPUT,
    REDIRECTION_APPEND,
    REDIRECTION_INPUT,
    REDIRECTION_HERE_DOCUMENT
} redirection_type_t;

redirection_t *redirection_new(redirection_type_t type, const char *value);
void redirection_delete(redirection_t *redirection);

redirection_type_t redirection_get_type(redirection_t *redirection);
char *redirection_get_value(redirection_t *redirection);

// Debug
void redirection_print(redirection_t *redirection);
