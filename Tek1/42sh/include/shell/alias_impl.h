/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_impl
*/

#pragma once

#include "shell/alias.h"
#include <stdbool.h>

struct alias {
    char *name;
    char **values;

    struct alias *next;
};

bool alias_set_name(alias_t *alias, char *name);
bool alias_set_values(alias_t *alias, char **values, void *method);
