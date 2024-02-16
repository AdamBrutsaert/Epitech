/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_get_next
*/

#include "shell/alias_impl.h"

alias_t *alias_get_next(alias_t *alias)
{
    return alias->next;
}
