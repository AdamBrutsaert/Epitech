/*
** EPITECH PROJECT, 2023
** parse_arg.c
** File description:
** parse_arg.c
*/

#include "head.h"
#include "my/string.h"

#include <stdlib.h>

void head_parse_arg(head_t *head, char *argument)
{
    uint64_t length = my_strarrlen(head->files);
    char **files = malloc(sizeof(char *) * (length + 2));

    for (uint64_t i = 0; i < length; i++)
        files[i] = head->files[i];
    files[length] = argument;
    files[length + 1] = NULL;
    free(head->files);
    head->files = files;
}
