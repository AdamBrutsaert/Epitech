/*
** EPITECH PROJECT, 2024
** file.h
** File description:
** file.h
*/

#pragma once

#include <fcntl.h>
#include <sys/types.h>

#include "string.h"

/*********************************** Types ***********************************/

/// Represents a file
typedef int file_t;

/// Represents a file mode
typedef enum {
    FILE_MODE_READ_ONLY = O_RDONLY,
    FILE_MODE_WRITE_ONLY = O_WRONLY,
    FILE_MODE_READ_WRITE = O_RDWR,
    FILE_MODE_APPEND = O_APPEND,
    FILE_MODE_CREATE = O_CREAT,
    FILE_MODE_TRUNC = O_TRUNC
} file_mode_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a file
file_t *file_create(void);

/// Destroy a file
void file_destroy(file_t *self);

/*****************************************************************************/

/****************************** Open and Close *******************************/

/// Opens a file
bool file_open(file_t *self, const char *filename, file_mode_t mode);

/// Closes a file
void file_close(file_t *self);

/// Checks if a file is opened
#define FILE_OPENED(self) (*self != -1)

/*****************************************************************************/

/**************************** Reading and Writing ****************************/

/// Reads data from a file
ssize_t file_read(file_t *self, void *buffer, size_t length);

/// Writes data to a file
ssize_t file_write(file_t *self, const void *buffer, size_t length);

/// Writes all data to a file
ssize_t file_write_all(file_t *self, const void *buffer, size_t length);

/// Reads whole file
string_t *file_read_all(file_t *self);

/*****************************************************************************/
