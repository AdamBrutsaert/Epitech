/*
** EPITECH PROJECT, 2023
** instruction_get_redirections.c
** File description:
** instruction_get_redirections.c
*/

#include "shell/instruction_impl.h"

vec_t *instruction_get_redirections(instruction_t *instruction)
{
    return instruction->redirections;
}
