/*
** EPITECH PROJECT, 2022
** argp.h
** File description:
** argp.h
*/

#pragma once

#include <stdint.h>

#define MY_ARGP_FLAG_PARAMETER 0x1
#define MY_ARGP_KEY_ARG INT16_MIN

typedef struct {
    int16_t key;
    char const *name;
    uint8_t flags;
} my_argp_option_t;

typedef struct {
    my_argp_option_t *options;
    void *configuration;
    void (*on_argument)(int16_t, char const *, void *);
} my_argp_t;

int32_t my_argp_parse(my_argp_t *argp, int argc, char **argv);
