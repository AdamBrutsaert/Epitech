/*
** EPITECH PROJECT, 2022
** argp.h
** File description:
** argp.h
*/

#pragma once

#include "../argp.h"

#include <stdint.h>

int8_t is_short_flag(char const *arg);
int8_t is_long_flag(char const *arg);
int8_t is_flag(char const *arg);
int8_t is_stop_flag(char const *arg);

int32_t get_key_index(my_argp_t *argp, int16_t flag);
int16_t get_long_flag_key(my_argp_t *argp, char const *flag);
