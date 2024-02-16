/*
** EPITECH PROJECT, 2022
** parse_file.c
** File description:
** parse_file.c
*/

#include "parser.h"

#include <my/stdio.h>
#include <stdio.h>
#include <stdlib.h>

static int32_t print_error(uint8_t code, char const *filepath, uint32_t line)
{
    if (code == 0) {
        my_eputs("[MyRadar][Script] Error: could not open file \"");
        my_eputs(filepath);
        my_eputs("\"!\n");
    }
    if (code == 1) {
        my_eputs("[MyRadar][Script] Error: invalid entity at line ");
        my_eputu(line);
        my_eputs("!\n");
    }
    if (code == 2)
        my_eputs("[MyRadar][Script] Error: there is no aircraft!\n");
    return 84;
}

uint32_t read_lines(FILE *file, vector_t *aircrafts, vector_t *towers)
{
    char *line = NULL;
    size_t n = 0;
    int8_t result = 0;
    uint32_t current_line = 0;

    while (result != 84 && getline(&line, &n, file) != -1) {
        result = parse_line(line, aircrafts, towers);
        free(line);
        line = NULL;
        n = 0;
        current_line++;
    }
    free(line);
    return result == 84 ? current_line : 0;
}

int32_t parse_file(char const *filepath, vector_t *aircrafts,
    vector_t *towers)
{
    FILE *file = fopen(filepath, "r");
    uint32_t result = 0;

    if (file == NULL)
        return print_error(0, filepath, 0);
    result = read_lines(file, aircrafts, towers);
    if (result != 0)
        return print_error(1, filepath, result);
    if (vector_length(aircrafts) == 0)
        return print_error(2, filepath, 0);
    fclose(file);
    return result;
}
