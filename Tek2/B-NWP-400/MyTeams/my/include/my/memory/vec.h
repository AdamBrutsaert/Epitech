/*
** EPITECH PROJECT, 2024
** vec.h
** File description:
** vec.h
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

/*********************************** Types ***********************************/

/// Represents a dynamic array of elements
typedef struct {
    uint8_t *data;
    size_t length;
    size_t capacity;
    size_t stride;
} vec_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a vector
vec_t *vec_create(size_t stride);

/// Destroys a vector
void vec_destroy(vec_t *self);

/*****************************************************************************/

/********************************** Getters **********************************/

#define VEC_DATA(self) ((void *)((self)->data))
#define VEC_CDATA(self) ((const void *)((self)->data))
#define VEC_STRIDE(self) ((self)->stride)
#define VEC_LEN(self) ((self)->length)
#define VEC_CAP(self) ((self)->capacity)
#define VEC_AT(self, i) ((void *)(self)->data + (i) * (self)->stride)
#define VEC_CAT(self, i) ((const void *)(self)->data + (i) * (self)->stride)
#define VEC_BEGIN(self) ((self)->data)
#define VEC_END(self) ((self)->data + (self)->length * (self)->stride)
#define VEC_FRONT(self) VEC_BEGIN(self)
#define VEC_BACK(self) VEC_AT(self, (self)->length - 1)

/*****************************************************************************/

/********************************* Capacity **********************************/

/// Reserves memory for the vector
void vec_reserve(vec_t *self, size_t capacity);

/// Reserves at least a certain amount of memory for the vector
void vec_reserve_at_least(vec_t *self, size_t capacity);

/*****************************************************************************/

/********************************** Adding ***********************************/

/// Pushes back a value to the vector
void vec_push_back(vec_t *self, const void *value);

/// Pushes back multiple values to the vector
void vec_push_back_some(vec_t *self, const void *values, size_t count);

/// Pushes back a 0-initialized value to the vector
void vec_push_back_zero(vec_t *self);

/// Pushes a back some 0-initialized values to the vector
void vec_push_back_some_zero(vec_t *self, size_t count);

/// Pushes front a value to the vector
void vec_push_front(vec_t *self, const void *value);

/// Pushes front multiple values to the vector
void vec_push_front_some(vec_t *self, const void *values, size_t count);

/// Inserts a value at a certain index
void vec_insert(vec_t *self, size_t index, const void *value);

/// Inserts multiple values at a certain index
void vec_insert_some(
    vec_t *self,
    size_t index,
    const void *values,
    size_t count
);

/// Remove a value at a certain index
void vec_remove(vec_t *self, size_t index);

/// Remove multiple values at a certain index
void vec_remove_some(vec_t *self, size_t index, size_t count);

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

/// Swaps two values in the vector
void vec_swap(vec_t *self, size_t index1, size_t index2);

/*****************************************************************************/
