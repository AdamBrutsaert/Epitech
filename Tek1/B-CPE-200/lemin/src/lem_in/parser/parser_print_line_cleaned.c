/*
** EPITECH PROJECT, 2023
** parser_print_line_cleaned.c
** File description:
** parser_print_line_cleaned.c
*/

#include "lem_in.h"
#include "my/string.h"
#include "my/stdio.h"

void parser_print_line_cleaned(char *line)
{
    for (size_t i = 0; line[i]; i++) {
        if (line[i] == '\n' || line[i] == '#') {
            line[i] = '\0';
            break;
        }
    }
    for (size_t end = my_strlen(line);
        line[end] == ' ' || line[end] == '#';
        end--)
        line[end] = '\0';
    my_puts(line);
    my_putc('\n');
}
