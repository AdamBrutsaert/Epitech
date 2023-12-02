/*
** EPITECH PROJECT, 2023
** sort.c
** File description:
** sort.c
*/

#include "string.h"

static int8_t is_sorted(char **array, uint64_t length)
{
    for (uint64_t i = 1; i < length; i++)
        if (my_strcmp(array[i], array[i - 1]) < 0)
            return 0;
    return 1;
}

static void swap_string(char **s1, char **s2)
{
    char *copy = *s1;

    *s1 = *s2;
    *s2 = copy;
}

static void bubble_sort(char **array, uint64_t length)
{
    for (uint64_t i = 1; i < length; i++)
        if (my_strcmp(array[i], array[i - 1]) < 0)
            swap_string(&array[i - 1], &array[i]);
}

void sort(char **array, uint64_t length)
{
    while (!is_sorted(array, length))
        bubble_sort(array, length);
}
