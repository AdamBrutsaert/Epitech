/*
** EPITECH PROJECT, 2023
** lexer_glob.h
** File description:
** lexer_glob.h
*/

#pragma once

#include "lexer.h"

static const char *TOKEN_NAMES[] = {
    [TOKEN_INSTRUCTION] = "[INSTRUCTION]   ",
    [TOKEN_COMMAND] = "[COMMAND]       ",
    [TOKEN_LABEL] = "[LABEL]         ",
    [TOKEN_REGISTER] = "[REGISTER]      ",
    [TOKEN_DIRECT_VALUE] = "[DIRECT_VALUE]  ",
    [TOKEN_DIRECT_LABEL] = "[DIRECT_LABEL]  ",
    [TOKEN_INDIRECT_VALUE] = "[INDIRECT_VALUE]",
    [TOKEN_INDIRECT_LABEL] = "[INDIRECT_LABEL]",
    [TOKEN_STRING] = "[STRING]        ",
    [TOKEN_SEPARATOR] = "[SEPARATOR]     ",
    [TOKEN_NEWLINE] = "[NEWLINE]       ",
    [TOKEN_EOF] = "[EOF]           "
};
