/*
** EPITECH PROJECT, 2024
** string.h
** File description:
** string.h
*/

#pragma once

#include "vec.h"

/*********************************** Types ***********************************/

/// Represents a string
typedef vec_t string_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates an empty string
string_t *string_create(void);

/// Creates a string from a C string
string_t *string_create_from_cstr(const char *cstr);

/// Creates a string from a buffer
string_t *string_create_from_buffer(const void *buffer, size_t size);

/// Creates a random UUID string
string_t *string_create_random_uuid(void);

/// Creates a string from an unsigned
string_t *string_create_from_unsigned(uint64_t number);

/// Clones a string
string_t *string_clone(const string_t *self);

/// Clones a maximum of n characters from a string
string_t *string_clone_n(const string_t *self, size_t n);

/// Destroys a string
void string_destroy(string_t *self);

/// Destroys a vector of strings
void string_destroy_vec(vec_t *vec);

/*****************************************************************************/

/********************************** Getters **********************************/

#define STRING_DATA(self) ((char *)VEC_DATA(self))
#define STRING_CDATA(self) ((const char *)VEC_CDATA(self))
#define STRING_LEN(self) (VEC_LEN(self) - 1)
#define STRING_AT(self, i) (*(char *)VEC_AT(self, i))

/*****************************************************************************/

/********************************** Methods **********************************/

/// Compares two strings
int16_t string_compare(const string_t *self, const string_t *other);

/// Compares a string with a string view
int16_t string_compare_cstr(const string_t *self, const char *other);

/// Returns true if a string contains a character
bool string_contains_char(const string_t *self, char c);

/// Inserts a string into another string
void string_insert(string_t *self, size_t offset, const string_t *other);

/// Inserts a c-string into a string
void string_insert_cstr(string_t *self, size_t offset, const char *cstr);

/// Removes a part of a string
void string_remove(string_t *self, size_t offset, size_t length);

/// Appends a string to a string
void string_append_string(string_t *self, const string_t *other);

/// Appends a c-string to a string
void string_append_cstr(string_t *self, const char *cstr);

/// Splits a string into a vector of strings
vec_t *string_split(const string_t *self, char delimiter);

/// Splits a string into a vector of strings by checking escaped delimiter
vec_t *string_split_escaped(const string_t *self, char delimiter);

/// Escape a character inside a string
void string_escape(string_t *self, char character);

/*****************************************************************************/
