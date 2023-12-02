/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** alias_process
*/

#include "shell.h"
#include "shell_impl.h"
#include "shell/instruction_impl.h"
#include "my/memory.h"

#include <string.h>
#include <stdlib.h>

char **dup_args(char **arguments)
{
    char **args = malloc(sizeof(char *) * (my_array_length(arguments) + 1));

    for (int i = 0; arguments[i] != NULL; i++) {
        args[i] = strdup(arguments[i]);
    }
    args[my_array_length(arguments)] = NULL;

    return args;
}

bool push_new_args(instruction_t *instruction, char **arguments,
    char **old_arguments)
{
    char *dup = NULL;

    for (int i = 0; arguments[i] != NULL; i++) {
        dup = strdup(arguments[i]);
        if (!dup || !VEC_PUSH(instruction->arguments, dup))
            return false;
    }
    for (int i = 1; old_arguments[i] != NULL; i++) {
        dup = strdup(old_arguments[i]);
        if (!dup || !VEC_PUSH(instruction->arguments, dup))
            return false;
    }
    my_array_free(old_arguments);
    return true;
}

bool replace_arguments(instruction_t *instruction, char **arguments)
{
    char **old_arguments = dup_args(instruction_get_arguments(instruction));
    void *dummy = NULL;

    vec_clear_and_delete(instruction->arguments, free);
    vec_delete(instruction->arguments);
    instruction->arguments = vec_new(sizeof(char *));
    if (!push_new_args(instruction, arguments, old_arguments))
        return false;
    if (!VEC_PUSH(instruction->arguments, dummy))
        return false;
    return true;
}

void shell_process_alias(shell_t *shell, instruction_t *instruction)
{
    char **arguments = instruction_get_arguments(instruction);

    for (alias_t *alias = shell->aliases; alias != NULL;
        alias = alias_get_next(alias)) {
        if (!strcmp(alias_get_name(alias), arguments[0])) {
            replace_arguments(instruction, alias_get_values(alias));
            return;
        }
    }
}
