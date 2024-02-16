/*
** EPITECH PROJECT, 2023
** head.h
** File description:
** head.h
*/

#pragma once

#include <stdbool.h>
#include <stdint.h>

#define FLAG_BYTES   0x1
#define FLAG_LINES   0x2
#define FLAG_QUIET   0x4
#define FLAG_VERBOSE 0x8

typedef struct {
    uint8_t flags;
    int64_t bytes;
    int64_t lines;
    char **files;
} head_t;

head_t *head_create(void);
void head_destroy(head_t *head);

int head_process(head_t *head);

int head_parse(head_t *head, char **arguments);
void head_parse_long(head_t *head, char *argument, bool *error);
bool head_parse_short(head_t *head, char *argument, char *value, bool *error);
void head_parse_arg(head_t *head, char *argument);
