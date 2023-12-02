/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-yanis.zeghiche
** File description:
** shell_get_history
*/

#include "shell_impl.h"

vec_t *shell_get_history(shell_t *shell)
{
    return (shell->history);
}
