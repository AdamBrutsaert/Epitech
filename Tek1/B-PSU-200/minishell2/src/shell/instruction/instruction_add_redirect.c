/*
** EPITECH PROJECT, 2023
** instruction_add_redirect.c
** File description:
** instruction_add_redirect.c
*/

#include "shell/instruction.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(instruction_t *instruction)
{
    size_t capacity = instruction->redirects_capacity * 2
        + !instruction->redirects_capacity;
    redirect_t *redirects = malloc(sizeof(redirect_t) * capacity);

    if (redirects == NULL)
        return false;
    my_memmove(
        redirects,
        instruction->redirects,
        sizeof(redirect_t) * instruction->redirects_length
    );
    free(instruction->redirects);
    instruction->redirects = redirects;
    instruction->redirects_capacity = capacity;
    return true;
}

bool instruction_add_redirect(
    instruction_t *instruction,
    redirect_type_t type,
    char *value
)
{
    if (instruction->redirects_length == instruction->redirects_capacity
        && !grow(instruction))
        return false;
    instruction->redirects[instruction->redirects_length].type = type;
    instruction->redirects[instruction->redirects_length].value = value;
    instruction->redirects_length++;
    return true;
}
