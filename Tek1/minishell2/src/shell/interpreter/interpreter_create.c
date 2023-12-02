/*
** EPITECH PROJECT, 2023
** interpreter_create.c
** File description:
** interpreter_create.c
*/

#include "shell/interpreter.h"
#include "my/memory.h"
#include "my/string.h"

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static bool redirect_input(int argc, char **argv)
{
    int fd;

    if (argc <= 1)
        return true;
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return false;
    if (dup2(fd, STDIN_FILENO) == -1) {
        close(fd);
        return false;
    }
    close(fd);
    return true;
}

static bool copy_env(interpreter_t *interpreter, char **env)
{
    size_t length = 0;

    while (env[length])
        length++;
    interpreter->env = malloc(sizeof(char *) * (length + 1));
    if (!interpreter->env)
        return false;
    for (size_t i = 0; i < length; i++) {
        interpreter->env[i] = my_strdup(env[i]);
        if (!interpreter->env[i])
            return false;
    }
    interpreter->env[length] = NULL;
    return true;
}

interpreter_t *interpreter_create(int argc, char **argv,
    __attribute__((unused)) char **envp)
{
    interpreter_t *interpreter = malloc(sizeof(interpreter_t));

    if (!interpreter)
        return NULL;
    my_memset(interpreter, 0, sizeof(interpreter_t));
    interpreter->reader = reader_create();
    interpreter->lexer = lexer_create(interpreter->reader);
    interpreter->parser = parser_create(interpreter->lexer);
    if (!interpreter->reader || !interpreter->lexer || !interpreter->parser
        || !redirect_input(argc, argv) || !copy_env(interpreter, envp)) {
        interpreter_destroy(interpreter);
        return NULL;
    }
    interpreter->exit = false;
    return interpreter;
}
