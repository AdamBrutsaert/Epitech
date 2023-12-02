/*
** EPITECH PROJECT, 2022
** file.h
** File description:
** file.h
*/

#pragma once

#include <stdint.h>
#include <time.h>
#include <limits.h>

#define FILE_TYPE_REGULAR '-'
#define FILE_TYPE_DIRECTORY 'd'
#define FILE_TYPE_CHARACTER_DEVICE 'c'
#define FILE_TYPE_BLOCK_DEVICE 'b'
#define FILE_TYPE_FIFO 'p'
#define FILE_TYPE_SYMBOLIC_LINK 'l'
#define FILE_TYPE_SOCKET 's'
#define FILE_TYPE_NONE '\0'

#define FILE_PERMISSION_UID 0x800
#define FILE_PERMISSION_GID 0x400
#define FILE_PERMISSION_STICKY 0x200
#define FILE_PERMISSION_UR 0x100
#define FILE_PERMISSION_UW 0x80
#define FILE_PERMISSION_UX 0x40
#define FILE_PERMISSION_GR 0x20
#define FILE_PERMISSION_GW 0x10
#define FILE_PERMISSION_GX 0x8
#define FILE_PERMISSION_OR 0x4
#define FILE_PERMISSION_OW 0x2
#define FILE_PERMISSION_OX 0x1

typedef struct {
    char type;
    uint16_t permission;
    uint64_t links;
    char const *owner;
    char const *group;
    uint64_t size;
    uint64_t blocks;
    uint64_t dev_major;
    uint64_t dev_minor;
    time_t last_modification;
    char *name;
    char symlink[PATH_MAX];
    char *path;
} file_t;

typedef struct {
    file_t *files;
    uint64_t length;
    uint64_t capacity;
} file_vector_t;

char *get_path(char const *directory, char const *file);
int32_t file_get(file_t *file, char *path, char *name);
int32_t file_read_directory(file_vector_t *vector, char const *file);

void file_vector_create(file_vector_t *vector);
void file_vector_destroy(file_vector_t *vector);
void file_vector_push(file_vector_t *vector, file_t *file);
void file_vector_sort(file_vector_t *files, int8_t by_time, int8_t reverse);
