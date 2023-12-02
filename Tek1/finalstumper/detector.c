/*
** EPITECH PROJECT, 2022
** detector.c
** File description:
** Implementation of detector
*/

#include "rush3.h"
#include "patterns.h"
#include "my.h"
#include <unistd.h>

static char is_same(char *tokens1, char *tokens2)
{
    for (int i = 0; i < 8; i++) {
        if (tokens1[i] != tokens2[i])
            return 0;
    }
    return 1;
}

static char is_matching(char *tokens, char **patterns)
{
    for (int i = 0; i < 9; i++) {
        if (is_same(tokens, patterns[i]))
            return 1;
    }
    return 0;
}

static void print_detected(int n, int width, int height, char first)
{
    if (!first)
        write(1, " || ", 4);
    write(1, "[rush-1-", 8);
    my_put_nbr(n);
    write(1, "] ", 2);
    my_put_nbr(width);
    write(1, " ", 1);
    my_put_nbr(height);
}

void detect(char *tokens, int width, int height)
{
    char first = 1;

    for (int i = 0; i < 5 && tokens; i++) {
        if (is_matching(tokens, PATTERNS[i])) {
            print_detected(i + 1, width, height, first);
            first = 0;
        }
    }
    if (first || !tokens)
        write(1, "none", 4);
    write(1, "\n", 1);
}
