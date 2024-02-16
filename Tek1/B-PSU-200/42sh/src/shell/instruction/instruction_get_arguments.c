/*
** EPITECH PROJECT, 2023
** instruction_get_arguments.c
** File description:
** instruction_get_arguments.c
*/

#include "shell/instruction_impl.h"

char **instruction_get_arguments(instruction_t *instruction)
{
    return VEC_DATA(instruction->arguments);
}
