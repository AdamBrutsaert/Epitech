/*
** EPITECH PROJECT, 2023
** compiler.h
** File description:
** compiler.h
*/

#pragma once

#include "lexer.h"

typedef struct compiler compiler_t;

compiler_t *compiler_new(void);
void compiler_delete(compiler_t *compiler);

bool compiler_process(compiler_t *compiler, lexer_t *lexer, const char *path);
