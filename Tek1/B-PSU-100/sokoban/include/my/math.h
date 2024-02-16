/*
** EPITECH PROJECT, 2022
** math.h
** File description:
** math.h
*/

#pragma once

#include "types.h"

i8_t my_i8_abs(i8_t number);
i16_t my_i16_abs(i16_t number);
i32_t my_i32_abs(i32_t number);
i64_t my_i64_abs(i64_t number);
f32_t my_f32_abs(f32_t number);

i8_t my_i8_min(i8_t a, i8_t b);
i16_t my_i16_min(i16_t a, i16_t b);
i32_t my_i32_min(i32_t a, i32_t b);
i64_t my_i64_min(i64_t a, i64_t b);
u8_t my_u8_min(u8_t a, u8_t b);
u16_t my_u16_min(u16_t a, u16_t b);
u32_t my_u32_min(u32_t a, u32_t b);
u64_t my_u64_min(u64_t a, u64_t b);
f32_t my_f32_min(f32_t a, f32_t b);

i8_t my_i8_max(i8_t a, i8_t b);
i16_t my_i16_max(i16_t a, i16_t b);
i32_t my_i32_max(i32_t a, i32_t b);
i64_t my_i64_max(i64_t a, i64_t b);
u8_t my_u8_max(u8_t a, u8_t b);
u16_t my_u16_max(u16_t a, u16_t b);
u32_t my_u32_max(u32_t a, u32_t b);
u64_t my_u64_max(u64_t a, u64_t b);
f32_t my_f32_max(f32_t a, f32_t b);

i8_t my_i8_clamp(i8_t number, i8_t min, i8_t max);
i16_t my_i16_clamp(i16_t number, i16_t min, i16_t max);
i32_t my_i32_clamp(i32_t number, i32_t min, i32_t max);
i64_t my_i64_clamp(i64_t number, i64_t min, i64_t max);
u8_t my_u8_clamp(u8_t number, u8_t min, u8_t max);
u16_t my_u16_clamp(u16_t number, u16_t min, u16_t max);
u32_t my_u32_clamp(u32_t number, u32_t min, u32_t max);
u64_t my_u64_clamp(u64_t number, u64_t min, u64_t max);
f32_t my_f32_clamp(f32_t number, f32_t min, f32_t max);
