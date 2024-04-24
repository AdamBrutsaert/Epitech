/*
** EPITECH PROJECT, 2024
** allocation.h
** File description:
** allocation.h
*/

#pragma once

#include <stddef.h>

/********************************* Functions *********************************/

/// Allocates some bytes
void *allocate(size_t bytes);

/// Rellocates some bytes
void *reallocate(void *memory, size_t bytes);

/// Deallocates some bytes
void deallocate(void *memory);

/*****************************************************************************/
