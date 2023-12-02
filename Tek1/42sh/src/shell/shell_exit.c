/*
** EPITECH PROJECT, 2023
** shell_exit.c
** File description:
** shell_exit.c
*/

#include "shell_impl.h"

void shell_exit(shell_t *shell)
{
    shell->exit = true;
}
