/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "split.h"
#include "sort.h"
#include "stdio.h"

void sort_words(char const *string)
{
    char **array = split(string);
    uint64_t length = split_length(array);

    sort(array, length);
    for (uint64_t i = 0; i < length; i++) {
        my_puts(array[i]);
        if (i + 1 != length)
            my_putc(' ');
    }
    my_putc('\n');
    split_free(array);
}

int main(int argc, char **argv)
{
    if (argc != 1 && argc != 2) {
        my_eputs("error: invalid number of arguments\n");
        my_eputs("info: you must provide 0 or 1 argument\n");
        return 84;
    }
    if (argc == 1)
        sort_words("");
    if (argc == 2)
        sort_words(argv[1]);
    return 0;
}
