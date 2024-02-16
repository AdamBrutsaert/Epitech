/*
** EPITECH PROJECT, 2023
** instruction_push_argument.c
** File description:
** instruction_push_argument.c
*/

#include "shell/instruction_impl.h"

#include <stdlib.h>
#include <string.h>

bool instruction_push_argument(
    instruction_t *instruction,
    const char *argument
)
{
    char *dup = strdup(argument);
    void *dummy = NULL;

    if (dup == NULL)
        return false;
    vec_pop(instruction->arguments);
    instruction_sanatize(dup);
    if (!VEC_PUSH(instruction->arguments, dup)) {
        free(dup);
        return false;
    }
    return VEC_PUSH(instruction->arguments, dummy);
}
