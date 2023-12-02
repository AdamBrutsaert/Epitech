/*
** EPITECH PROJECT, 2023
** asm.h
** File description:
** asm.h
*/

#pragma once

#include <stdbool.h>

typedef struct asm asm_t;

int asm_from_args(int argc, char **argv);

asm_t *asm_new(void);
void asm_delete(asm_t *asm);

void asm_help(const char *program);
bool asm_process(asm_t *asm, const char *filepath);
