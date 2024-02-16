/*
** EPITECH PROJECT, 2022
** configuration.c
** File description:
** configuration.c
*/

#include "my/details/ls.h"
#include "my/string.h"

#include <stdlib.h>
#include <stdio.h>

void configuration_create(configuration_t *config)
{
    config->flags = 0;
    config->error = 0;
    config->args_count = 0;
    file_vector_create(&config->folders);
    file_vector_create(&config->files);
}

void configuration_destroy(configuration_t *config)
{
    file_vector_destroy(&config->folders);
    file_vector_destroy(&config->files);
}

static void on_parameter(char const *value, configuration_t *config)
{
    file_t file;
    char *name = my_strdup(value);
    char *path = my_strdup(value);

    config->args_count++;
    if (file_get(&file, path, name)) {
        config->error = 84;
        perror(value);
        free(name);
        free(path);
        return;
    }
    if (file.type == FILE_TYPE_DIRECTORY) {
        file_vector_push(&config->folders, &file);
    } else {
        file_vector_push(&config->files, &file);
    }
}

static void on_argument(int16_t key, char const *value, void *configuration)
{
    configuration_t *config = (configuration_t *)configuration;

    if (key == 'a')
        config->flags |= FLAG_ALL;
    if (key == 'l')
        config->flags |= FLAG_LONG_LISTING;
    if (key == 'R')
        config->flags |= FLAG_RECURSIVE;
    if (key == 'd')
        config->flags |= FLAG_DIRECTORY;
    if (key == 'r')
        config->flags |= FLAG_SORT_REVERSE;
    if (key == 't')
        config->flags |= FLAG_SORT_TIME;
    if (key == MY_ARGP_KEY_ARG)
        on_parameter(value, config);
}

int32_t parse_arguments(configuration_t *config, int argc, char **argv)
{
    my_argp_option_t options[] = {
        { 'l', NULL, 0 },
        { 'a', NULL, 0 },
        { 'r', NULL, 0 },
        { 't', NULL, 0 },
        { 'd', NULL, 0 },
        { 'R', NULL, 0 },
        { 0, NULL, 0 },
    };
    my_argp_t argp = {
        options,
        config,
        on_argument
    };

    return my_argp_parse(&argp, argc, argv);
}
