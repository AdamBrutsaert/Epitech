/*
** EPITECH PROJECT, 2022
** types.h
** File description:
** types.h
*/

#pragma once

#include <stdint.h>

#define nullptr ((void*)0)

#define true  1
#define false 0

#define STATUS_SUCCESS  0
#define STATUS_ERROR    84
#define STATUS_LOWER   -1
#define STATUS_EQUAL    0
#define STATUS_GREATER  1

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef uint64_t u64_t;

typedef int8_t i8_t;
typedef int16_t i16_t;
typedef int32_t i32_t;
typedef int64_t i64_t;

typedef float f32_t;

typedef i8_t status_t;
typedef i8_t bool_t;
