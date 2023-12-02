/*
** EPITECH PROJECT, 2023
** asm_help.c
** File description:
** asm_help.c
*/

#include "asm.h"
#include "my/stdio.h"

static void print_usage(const char *program)
{
    my_putcs("USAGE\n    ");
    my_putcs(program);
    my_putcs(" file_name[.s] [-h]\n\n");
}

static void print_description(void)
{
    my_putcs("DESCRIPTION\n");
    my_putcs("    file_name file in assembly language to be converted into ");
    my_putcs("file_name.cor, an\n");
    my_putcs("    executable in the Virtual Machine.\n");
}

void asm_help(const char *program)
{
    print_usage(program);
    print_description();
}
