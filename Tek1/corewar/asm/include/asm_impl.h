/*
** EPITECH PROJECT, 2023
** asm_impl.h
** File description:
** asm_impl.h
*/

#pragma once

#include "asm.h"
#include "asm/compiler.h"

struct asm {
    reader_t *reader;
    lexer_t *lexer;
    compiler_t *compiler;
};
