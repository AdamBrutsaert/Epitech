/*
** EPITECH PROJECT, 2023
** instruction_print.c
** File description:
** instruction_print.c
*/

#include "shell/instruction_impl.h"

#include <stdio.h>

void instruction_print(instruction_t *instruction)
{
    printf("\t\tInstruction:\n");
    printf("\t\t\tArguments:\n");
    for (size_t i = 0; i + 1 < VEC_LEN(instruction->arguments); i++)
        printf("\t\t\t\t%s\n", VEC_GET(instruction->arguments, i, char *));
    printf("\t\t\tRedirections:\n");
    for (size_t i = 0; i < VEC_LEN(instruction->redirections); i++) {
        redirection_print(VEC_GET(
            instruction->redirections,
            i,
            redirection_t *)
        );
    }
}
