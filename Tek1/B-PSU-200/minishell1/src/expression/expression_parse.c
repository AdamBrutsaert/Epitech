/*
** EPITECH PROJECT, 2023
** expression_parse.c
** File description:
** expression_parse.c
*/

#include "expression.h"
#include "my/error.h"

char **expression_parse(char const *string)
{
    char **arguments = expression_split(string);

    if (ERROR != OK)
        THROW_NULL(ERROR_ALLOCATION);
    expression_sanatize(arguments);
    return arguments;
}
