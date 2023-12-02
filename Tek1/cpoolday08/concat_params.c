/*
** EPITECH PROJECT, 2022
** concat_params
** File description:
** Implementation of concat_params
*/

#include <stdlib.h>
#include "my.h"

static void concat(int argc, char **argv, char *str)
{
    unsigned int offset = 0;

    for (int i = 0; i < argc; i++) {
        my_strcpy(str + offset, argv[i]);
        offset += my_strlen(argv[i]) + 1;
        str[offset - 1] = '\n';
    }
    str[offset - 1] = '\0';
}

char *concat_params(int argc, char **argv)
{
    unsigned int length = argc;
    char *str = 0;

    for (int i = 0; i < argc; i++)
        length += my_strlen(argv[i]);
    if (length > 0)
        str = malloc(sizeof(char) * length);
    if (str)
        concat(argc, argv, str);
    return str;
}
