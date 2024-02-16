/*
** EPITECH PROJECT, 2023
** interpreter_unset_env.c
** File description:
** interpreter_unset_env.c
*/

#include "shell/interpreter.h"
#include "my/string.h"
#include "my/memory.h"

#include <stdlib.h>

static size_t get_index(interpreter_t *interpreter, const char *name)
{
    size_t length = my_strlen(name);
    size_t index = 0;

    for (; interpreter->env[index]; index++) {
        if (!my_strncmp(interpreter->env[index], name, length)
            && interpreter->env[index][length] == '=')
            return index;
    }
    return index;
}

void interpreter_unset_env(
    interpreter_t *interpreter,
    const char *name
)
{
    size_t index = get_index(interpreter, name);
    size_t length = 0;

    if (interpreter->env[index] == NULL)
        return;
    while (interpreter->env[length] != NULL)
        length++;
    free(interpreter->env[index]);
    my_memmove(&interpreter->env[index], &interpreter->env[index + 1],
        (length - index) * sizeof(char *));
}
