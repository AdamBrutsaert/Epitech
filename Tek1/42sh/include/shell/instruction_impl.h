/*
** EPITECH PROJECT, 2023
** instruction_impl.h
** File description:
** instruction_impl.h
*/

#pragma once

#include "instruction.h"

struct instruction {
    vec_t *redirections;
    vec_t *arguments;
};

char *instruction_sanatize(char *string);
