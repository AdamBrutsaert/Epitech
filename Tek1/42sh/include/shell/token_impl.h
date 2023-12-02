/*
** EPITECH PROJECT, 2023
** token_impl.h
** File description:
** token_impl.h
*/

#pragma once

#include "token.h"

struct token {
    token_type_t type;
    char *value;
};
