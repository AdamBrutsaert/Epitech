/*
** EPITECH PROJECT, 2023
** interpreter_set_env.c
** File description:
** interpreter_set_env.c
*/

#include "shell/interpreter.h"
#include "my/string.h"

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

static char *concat(const char *name, const char *value)
{
    char *var = malloc(my_strlen(name) + my_strlen(value) + 2);

    if (var == NULL)
        return NULL;
    return my_strcat(my_strcat(my_strcpy(var, name), "="), value);
}

static bool push(
    interpreter_t *interpreter,
    const char *name,
    const char *value
)
{
    size_t length = 0;
    char **env;
    char *var = concat(name, value);

    if (var == NULL)
        return false;
    while (interpreter->env[length] != NULL)
        length++;
    env = malloc(sizeof(char *) * (length + 2));
    if (env == NULL) {
        free(var);
        return false;
    }
    for (size_t i = 0; i < length; i++)
        env[i] = interpreter->env[i];
    env[length] = var;
    env[length + 1] = NULL;
    free(interpreter->env);
    interpreter->env = env;
    return true;
}

static bool replace(
    interpreter_t *interpreter,
    size_t index,
    const char *name,
    const char *value
)
{
    char *var = concat(name, value);

    if (var == NULL)
        return false;
    free(interpreter->env[index]);
    interpreter->env[index] = var;
    return true;
}

bool interpreter_set_env(
    interpreter_t *interpreter,
    const char *name,
    const char *value
)
{
    size_t index = get_index(interpreter, name);

    if (interpreter->env[index] == NULL)
        return push(interpreter, name, value);
    return replace(interpreter, index, name, value);
}
