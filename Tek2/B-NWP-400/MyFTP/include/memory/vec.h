/*
** EPITECH PROJECT, 2024
** vec.h
** File description:
** vec.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/****************************** Data structures ******************************/

/// Represents a dynamic array of elements
typedef struct {
    uint8_t *data;
    size_t length;
    size_t capacity;
    size_t stride;
} vec_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the vector
void vec_init(vec_t *self, size_t stride);

/// Deinitializes the vector
void vec_deinit(vec_t *self);

/*****************************************************************************/

/********************************** Getters **********************************/

/// Returns the data of the vector
void *vec_data(vec_t *self);

/// Returns the length of the vector
size_t vec_length(const vec_t *self);

/// Returns the capacity of the vector
size_t vec_capacity(const vec_t *self);

/// Returns the stride of the vector
size_t vec_stride(const vec_t *self);

/// Retrieves a value from the vector
void *vec_get(vec_t *self, size_t index);

/*****************************************************************************/

/********************************* Capacity **********************************/

/// Reserve memory for the vector
bool vec_reserve(vec_t *self, size_t capacity);

/// Reserve at least a certain amount of memory for the vector
bool vec_reserve_at_least(vec_t *self, size_t capacity);

/*****************************************************************************/

/********************************** Adding ***********************************/

/// Push a value to the vector
bool vec_push(vec_t *self, const void *value);

/// Push multiple values to the vector
bool vec_push_some(vec_t *self, const void *values, size_t length);

/*****************************************************************************/

/********************************* Removing **********************************/

/// Removes all the values of the vector
void vec_clear(vec_t *self);

/// Removes last value of the vector
void vec_pop_back(vec_t *self);

/// Removes last values of the vector
void vec_pop_some_back(vec_t *self, size_t count);

/// Removes first value of the vector
void vec_pop_front(vec_t *self);

/// Removes first values of the vector
void vec_pop_some_front(vec_t *self, size_t count);

/*****************************************************************************/

/********************************** Utils ************************************/

/// Swap two values in the vector
bool vec_swap(vec_t *self, size_t index1, size_t index2);

/*****************************************************************************/
