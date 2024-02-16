/*
** EPITECH PROJECT, 2022
** ls.c
** File description:
** ls.c
*/

#include "my/details/ls.h"
#include "my/details/file.h"
#include "my/stdio.h"
#include "my/string.h"
#include "my/memory.h"

static void process_files(configuration_t *config)
{
    file_t file;

    if (config->flags & FLAG_DIRECTORY) {
        for (uint64_t i = 0; i < config->folders.length; i++) {
            my_memcpy(&file, &config->folders.files[i], sizeof(file_t));
            file.name = my_strdup(file.name);
            file.path = my_strdup(file.path);
            file_vector_push(&config->files, &file);
        }
    }
    file_vector_sort(&config->files,
        config->flags & FLAG_SORT_TIME, config->flags & FLAG_SORT_REVERSE);
    for (uint32_t i = 0; i < config->files.length; i++)
        process_file(&config->files.files[i], config->flags);
}

static int32_t process_directories(configuration_t *config)
{
    int32_t error = 0;

    file_vector_sort(&config->folders,
        config->flags & FLAG_SORT_TIME, config->flags & FLAG_SORT_REVERSE);
    for (uint32_t i = 0; i < config->folders.length; i++) {
        if (!(config->flags & FLAG_DIRECTORY))
            error |= process_directory(&config->folders.files[i], config->flags,
                config->files.length || i > 0, config->args_count > 1);
    }
    return error;
}

int32_t my_ls(int argc, char **argv)
{
    configuration_t config;
    file_t file;
    int error = 0;

    configuration_create(&config);
    if (parse_arguments(&config, argc, argv)) {
        configuration_destroy(&config);
        return 84;
    }
    if (!config.args_count) {
        file_get(&file, my_strdup("."), my_strdup("."));
        file_vector_push(&config.folders, &file);
    }
    process_files(&config);
    error += process_directories(&config);
    configuration_destroy(&config);
    return error || config.error ? 84 : 0;
}
