/*
** EPITECH PROJECT, 2022
** parse_line.c
** File description:
** parse_line.c
*/

#include "parser.h"

#include <my/string.h>
#include <my/memory.h>

static uint64_t get_word_count(char const *line)
{
    uint64_t count = 0;
    int8_t blank = 1;

    for (; *line; line++) {
        if (*line == ' ' || *line == '\t' || *line == '\n') {
            blank = 1;
            continue;
        }
        if (blank) {
            blank = 0;
            count++;
        }
    }
    return count;
}

static char *get_next_word(char const **line)
{
    char const *begin;

    while (**line == ' ' || **line == '\t' || **line == '\n')
        (*line)++;
    begin = *line;
    while (**line && **line != ' ' && **line != '\t' && **line != '\n')
        (*line)++;
    return my_strndup(begin, *line - begin);
}

int32_t parse_line(char const *line, vector_t *aircrafts, vector_t *towers)
{
    uint64_t word_count = get_word_count(line);
    char **words = my_malloc(word_count * sizeof(char *));
    int32_t status = 84;

    for (uint64_t i = 0; i < word_count; i++)
        words[i] = get_next_word(&line);
    if (word_count && !my_strcmp(words[0], "A"))
        status = parse_aircraft(words, word_count, aircrafts);
    if (word_count && !my_strcmp(words[0], "T"))
        status = parse_tower(words, word_count, towers);
    if (word_count == 0)
        status = 0;
    for (uint64_t i = 0; i < word_count; i++)
        my_free(words[i]);
    my_free(words);
    return status;
}
