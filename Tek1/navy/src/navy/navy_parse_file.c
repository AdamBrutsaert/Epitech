/*
** EPITECH PROJECT, 2023
** navy_parse_file.c
** File description:
** navy_parse_file.c
*/

#include "navy.h"

#include "my.h"

#include <stdio.h>
#include <stdlib.h>

static int8_t place_boat(navy_t *navy, char const *line, uint32_t line_no)
{
    if (line[2] != line[5] && line[3] != line[6])
        return 84;
    if (line[5] - line[2] != (int64_t)(line_no)
        && line[6] - line[3] != (int64_t)(line_no))
        return 84;
    if (line[2] == line[5]) {
        for (uint32_t i = 0; i < line_no + 1; i++)
            navy->self[line[3] - '1' + i][line[2] - 'A'] = line_no + 1;
    } else {
        for (uint32_t i = 0; i < line_no + 1; i++)
            navy->self[line[3] - '1'][line[2] - 'A' + i] = line_no + 1;
    }
    return 0;
}

static int8_t parse_line(navy_t *navy, char const *line, uint32_t line_no)
{
    if (line_no > 4)
        return 84;
    if (my_strlen(line) != 8)
        return 84;
    if ((uint32_t)*line != '1' + line_no)
        return 84;
    if (line[1] != ':' || line[4] != ':')
        return 84;
    if (line[2] < 'A' || line[2] > 'H' || line[3] < '1' || line[3] > '8')
        return 84;
    if (line[5] < 'A' || line[5] > 'H' || line[6] < '1' || line[6] > '8')
        return 84;
    if (place_boat(navy, line, line_no) == 84)
        return 84;
    return 0;
}

int8_t navy_parse_file(navy_t *navy, char const *path)
{
    FILE *file = fopen(path, "r");
    char *line = NULL;
    size_t n = 0;
    uint32_t line_no = 0;
    int8_t result = 0;

    if (!file)
        return 84;
    while (result != 84 && getline(&line, &n, file) != -1) {
        line_no++;
        result = parse_line(navy, line, line_no);
    }
    free(line);
    fclose(file);
    if (line_no < 4)
        return 84;
    return result;
}
