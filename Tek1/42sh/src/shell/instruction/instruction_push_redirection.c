/*
** EPITECH PROJECT, 2023
** instruction_push_redirection.c
** File description:
** instruction_push_redirection.c
*/

#include "shell/instruction_impl.h"

bool instruction_push_redirection(
    instruction_t *instruction,
    redirection_t *redirection
)
{
    return VEC_PUSH(instruction->redirections, redirection);
}
