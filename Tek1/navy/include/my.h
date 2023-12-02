/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#pragma once

#include <stdint.h>
#include <signal.h>

void *my_memmove(void *dest, void const *src, uint64_t bytes);

int64_t my_abs(int64_t value);

uint64_t my_strlen(char const *string);
int16_t my_strcmp(char const *s1, char const *s2);

void my_putc(char character);
void my_puts(char const *string);
void my_puti(int64_t number);

int8_t is_pid(char const *string);
pid_t str_to_pid(char const *string);
