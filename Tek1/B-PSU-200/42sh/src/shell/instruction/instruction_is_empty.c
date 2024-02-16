/*
** EPITECH PROJECT, 2023
** instruction_is_empty.c
** File description:
** instruction_is_empty.c
*/

#include "shell/instruction_impl.h"

bool instruction_is_empty(instruction_t *instruction)
{
    return VEC_LEN(instruction->arguments) == 1;
}
