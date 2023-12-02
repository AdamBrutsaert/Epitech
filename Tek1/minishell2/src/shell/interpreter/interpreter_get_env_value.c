/*
** EPITECH PROJECT, 2023
** interpreter_get_env_value.c
** File description:
** interpreter_get_env_value.c
*/

#include "shell/interpreter.h"
#include "my/string.h"

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

char *interpreter_get_env_value(interpreter_t *interpreter, const char *name)
{
    size_t index = get_index(interpreter, name);

    if (interpreter->env[index] == NULL)
        return NULL;
    return my_strdup(interpreter->env[index] + my_strlen(name) + 1);
}
