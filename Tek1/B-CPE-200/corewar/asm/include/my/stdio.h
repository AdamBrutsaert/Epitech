/*
** EPITECH PROJECT, 2023
** stdio.h
** File description:
** stdio.h
*/

#pragma once

#include "arena.h"
#include "string.h"

#include <stdint.h>

void my_puts(string_t *string);
void my_putcs(const char *string);
void my_putc(char c);
void my_putu(uintmax_t nb);

void my_eputs(string_t *string);
void my_eputcs(const char *string);
void my_eputc(char c);
void my_eputu(uintmax_t nb);
