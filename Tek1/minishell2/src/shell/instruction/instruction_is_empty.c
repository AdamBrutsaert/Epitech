/*
** EPITECH PROJECT, 2023
** instruction_is_empty.c
** File description:
** instruction_is_empty.c
*/

#include "shell/instruction.h"

bool instruction_is_empty(instruction_t *instruction)
{
    return instruction->arguments_length == 0;
}
