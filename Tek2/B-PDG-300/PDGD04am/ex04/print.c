/*
** EPITECH PROJECT, 2024
** print.c
** File description:
** print.c
*/

#include "print.h"

#include <string.h>
#include <unistd.h>

void print_normal(const char *str)
{
    write(STDOUT_FILENO, str, strlen(str));
    write(STDOUT_FILENO, "\n", 1);
}

void print_reverse(const char *str)
{
    for (size_t i = strlen(str); i > 0; i--)
        write(STDOUT_FILENO, &str[i - 1], 1);
    write(STDOUT_FILENO, "\n", 1);
}

void print_upper(const char *str)
{
    for (char c; *str; str++) {
        c = *str - (*str >= 'a' && *str <= 'z') * 32;
        write(STDOUT_FILENO, &c, 1);
    }
    write(STDOUT_FILENO, "\n", 1);
}

void print_42(__attribute__((unused)) const char *str)
{
    write(STDOUT_FILENO, "42\n", 3);
}

void do_action(action_t action, const char *str)
{
    static void (*actions[PRINT_COUNT])(const char *) = {
        [PRINT_NORMAL] = print_normal,
        [PRINT_REVERSE] = print_reverse,
        [PRINT_UPPER] = print_upper,
        [PRINT_42] = print_42,
    };

    (*actions[action])(str);
}
