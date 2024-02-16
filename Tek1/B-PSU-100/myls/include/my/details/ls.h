/*
** EPITECH PROJECT, 2022
** ls.h
** File description:
** ls.h
*/

#pragma once

#include "../ls.h"
#include "../argp.h"
#include "../file.h"

#include <stddef.h>

#define FLAG_ALL 0x1
#define FLAG_LONG_LISTING 0x2
#define FLAG_RECURSIVE 0x4
#define FLAG_DIRECTORY 0x8
#define FLAG_SORT_REVERSE 0x10
#define FLAG_SORT_TIME 0x20

typedef uint8_t flags_t;

typedef struct {
    flags_t flags;
    file_vector_t folders;
    file_vector_t files;
    uint32_t args_count;
    int error;
} configuration_t;

void configuration_create(configuration_t *config);
void configuration_destroy(configuration_t *config);
int32_t parse_arguments(configuration_t *config, int argc, char **argv);

void print_file(file_t *file, int8_t long_listing);
void print_directory(char const *name, file_vector_t *files, int8_t all,
    int8_t long_listing);

int32_t process_directory(file_t *file, flags_t flags, int8_t prefix,
    int8_t show_name);
void process_file(file_t *file, flags_t flags);
