/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "shell.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static void print_builtins(void)
{
    printf("    It can perform the following builtins:\n");
    printf("        - cd\n");
    printf("        - echo\n");
    printf("        - setenv\n");
    printf("        - unsetenv\n");
    printf("        - env\n");
    printf("        - exit\n\n");
}

static void print_operators(void)
{
    printf("    It can also perform the following operators:\n");
    printf("        - && : make fclean && make -j 12\n");
    printf("        - || : make || echo 'Build fails'\n");
    printf("        - ;  : make re; ./42sh\n");
    printf("        - |  : cat Makefile | wc -l\n\n");
    printf("    It can also perform the following redirections:\n");
    printf("        - <  : cat < Makefile\n");
    printf("        - >  : echo 'test' > file\n");
    printf("        - >> : echo 'yolo' >> file\n");
    printf("        - << : cat << EOF\n");
    printf("             $> hello\n");
    printf("             $> i'm under the water\n");
    printf("             $> please help me\n");
    printf("             $> EOF\n");
}

static int print_help(char **argv)
{
    printf("NAME:\n    YASH - Yanis Adam Adam Alexandre Shell\n\n");
    printf("SYNOPSIS:\n    %s [-h] : print help\n\n", argv[0]);
    printf("DESCRIPTION:\n");
    printf("    Our beautiful shell that allows to launch system ");
    printf("commands as well as some builtins that we have implemented.\n\n");
    print_builtins();
    print_operators();
    return 0;
}

static void print_ascii(void)
{
    printf("\n\n\n");
    printf("▄██   ▄      ▄████████    ▄████████    ▄█    █▄       ▄████████\n");
    printf("███   ██▄   ███    ███   ███    ███   ███    ███     ███    ███\n");
    printf("███▄▄▄███   ███    ███   ███    █▀    ███    ███     ███    █▀\n");
    printf("▀▀▀▀▀▀███   ███    ███   ███         ▄███▄▄▄▄███▄▄  ▄███▄▄▄\n");
    printf("▄██   ███ ▀███████████ ▀███████████ ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀\n");
    printf("███   ███   ███    ███          ███   ███    ███     ███    █▄\n");
    printf("███   ███   ███    ███    ▄█    ███   ███    ███     ███    ███\n");
    printf(" ▀█████▀    ███    █▀   ▄████████▀    ███    █▀      ██████████\n");
    printf("\n Designed by Yanis, Adam, Adam and Alexandre.\n\n\n");
}

int main(int argc, char **argv, char **envp)
{
    shell_t *shell = shell_new(argc, argv, envp);
    int status;

    if (argc > 1 && strcmp(argv[1], "-h") == 0)
        return print_help(argv);
    if (shell == NULL)
        return 84;
    if (isatty(STDIN_FILENO))
        print_ascii();
    status = shell_run(shell);
    shell_delete(shell);
    return status;
}
