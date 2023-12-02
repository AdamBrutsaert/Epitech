/*
** EPITECH PROJECT, 2023
** antman_from_arguments.c
** File description:
** antman_from_arguments.c
*/

#include "antman.h"
#include "my/string.h"
#include "my/stdio.h"

#include <stddef.h>

int8_t return_with_help(antman_t *antman, char *program)
{
    my_eputs("Antman, a file compression software\n\n");
    my_eputs("USAGE\n");
    my_eputs("    ");
    my_eputs(program);
    my_eputs(" <filepath> <type>\n\n");
    my_eputs("DESCRIPTION\n\n");
    my_eputs("    <filepath>    path to the file to be compressed\n");
    my_eputs("    <type>        type of the file\n");
    my_eputs("                      '1': text\n");
    my_eputs("                      '2': HTML\n");
    my_eputs("                      '3': P3 PPM\n");
    antman_destroy(antman);
    return ANTMAN_OK;
}

int8_t return_with_error(antman_t *antman, uint8_t code)
{
    if (code == 0) {
        my_eputs("error: invalid number of arguments\n");
        my_eputs("info: try again with -h\n");
    }
    if (code == 1) {
        my_eputs("error: invalid file type\n");
        my_eputs("info: available file type: 1, 2 or 3\n");
    }
    if (code == 2) {
        my_eputs("error: failed to allocate\n");
    }
    antman_destroy(antman);
    return ANTMAN_ERROR;
}

static int8_t parse_file_type(antman_t *antman, char const *arg)
{
    type_t type = NONE;

    if (!my_strcmp(arg, "1"))
        type = TEXT;
    if (!my_strcmp(arg, "2"))
        type = HTML;
    if (!my_strcmp(arg, "3"))
        type = P3PPM;
    antman_set_type(antman, type);
    return type == NONE ? ANTMAN_ERROR : ANTMAN_OK;
}

int8_t antman_from_arguments(int argc, char **argv)
{
    antman_t *antman = antman_create();
    int8_t status = ANTMAN_OK;

    if (antman == NULL)
        return return_with_error(antman, 2);
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return return_with_help(antman, argv[0]);
    if (argc != 3)
        return return_with_error(antman, 0);
    antman_set_file(antman, argv[1]);
    if (parse_file_type(antman, argv[2]))
        return_with_error(antman, 1);
    status = antman_compress(antman);
    antman_destroy(antman);
    return status;
}
