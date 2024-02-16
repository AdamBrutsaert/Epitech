/*
** EPITECH PROJECT, 2023
** save_impl.h
** File description:
** save_impl.h
*/

#pragma once

#include "save.h"

#include <stdbool.h>

#define SAVE_FILE "rpg.save"

void save_default(void);

void save_write_char(int fd, char value);
void save_write_u32(int fd, uint32_t value);
void save_write_i32(int fd, int32_t value);

bool save_read_char(char **buffer, char *value);
bool save_read_u32(char **buffer, uint32_t *value);
bool save_read_i32(char **buffer, int32_t *value);
