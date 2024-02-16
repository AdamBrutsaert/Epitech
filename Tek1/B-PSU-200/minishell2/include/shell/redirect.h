/*
** EPITECH PROJECT, 2023
** redirect.h
** File description:
** redirect.h
*/

#pragma once

typedef enum {
    REDIRECT_INPUT,
    REDIRECT_OUTPUT,
    REDIRECT_APPEND,
    REDIRECT_HERE_DOCUMENT
} redirect_type_t;

typedef struct {
    redirect_type_t type;
    char *value;
} redirect_t;
