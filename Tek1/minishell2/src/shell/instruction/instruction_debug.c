/*
** EPITECH PROJECT, 2023
** instruction_debug.c
** File description:
** instruction_debug.c
*/

#include "shell/instruction.h"
#include "my/stdio.h"

static void print_arguments(instruction_t *instruction)
{
    my_puts("      Arguments:\n");
    for (size_t i = 0; i < instruction->arguments_length; i++) {
        my_puts("        ");
        my_puts(instruction->arguments[i]);
        my_putc('\n');
    }
}

static void print_redirects(instruction_t *instruction)
{
    my_puts("      Redirects:\n");
    for (size_t i = 0; i < instruction->redirects_length; i++) {
        my_puts("        ");
        if (instruction->redirects[i].type == REDIRECT_INPUT)
            my_puts("< ");
        if (instruction->redirects[i].type == REDIRECT_OUTPUT)
            my_puts("> ");
        if (instruction->redirects[i].type == REDIRECT_APPEND)
            my_puts(">> ");
        if (instruction->redirects[i].type == REDIRECT_HERE_DOCUMENT)
            my_puts("<< ");
        my_puts(instruction->redirects[i].value);
        my_putc('\n');
    }
}

void instruction_debug(instruction_t *instruction)
{
    my_puts("    Instruction:\n");
    print_arguments(instruction);
    print_redirects(instruction);
}
