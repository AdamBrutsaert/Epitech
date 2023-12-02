/*
** EPITECH PROJECT, 2023
** redirection_print.c
** File description:
** redirection_print.c
*/

#include "shell/redirection_impl.h"

#include <stdio.h>

void redirection_print(redirection_t *redirection)
{
    printf("\t\t\t\t");
    if (redirection->type == REDIRECTION_OUTPUT)
        printf("> ");
    if (redirection->type == REDIRECTION_INPUT)
        printf("< ");
    if (redirection->type == REDIRECTION_APPEND)
        printf(">> ");
    if (redirection->type == REDIRECTION_HERE_DOCUMENT)
        printf("<< ");
    printf("%s\n", redirection->value);
}
