/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias
*/

#pragma once


#include <stdbool.h>

typedef struct alias alias_t;

char **alias_get_values(alias_t *alias);
char *alias_get_name(alias_t *alias);
alias_t *alias_get_next(alias_t *alias);
void alias_delete_all(alias_t *alias);
void alias_destroy(alias_t *alias);
char **alias_find_values(alias_t *alias, char *name);
