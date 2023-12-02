/*
** EPITECH PROJECT, 2023
** giantman_from_arguments.c
** File description:
** giantman_from_arguments.c
*/

#include "giantman.h"
#include "my/string.h"
#include "my/stdio.h"

#include <stddef.h>

int8_t return_with_help(giantman_t *giantman, char *program)
{
    my_eputs("Giantman, a file uncompression software\n\n");
    my_eputs("USAGE\n");
    my_eputs("    ");
    my_eputs(program);
    my_eputs(" <filepath> <type>\n\n");
    my_eputs("DESCRIPTION\n\n");
    my_eputs("    <filepath>    path to the file to be uncompressed\n");
    my_eputs("    <type>        type of the file\n");
    my_eputs("                      '1': text\n");
    my_eputs("                      '2': HTML\n");
    my_eputs("                      '3': P3 PPM\n");
    giantman_destroy(giantman);
    return GIANTMAN_OK;
}

int8_t return_with_error(giantman_t *giantman, uint8_t code)
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
    giantman_destroy(giantman);
    return GIANTMAN_ERROR;
}

static int8_t parse_file_type(giantman_t *giantman, char const *arg)
{
    type_t type = NONE;

    if (!my_strcmp(arg, "1"))
        type = TEXT;
    if (!my_strcmp(arg, "2"))
        type = HTML;
    if (!my_strcmp(arg, "3"))
        type = P3PPM;
    giantman_set_type(giantman, type);
    return type == NONE ? GIANTMAN_ERROR : GIANTMAN_OK;
}

int8_t giantman_from_arguments(int argc, char **argv)
{
    giantman_t *giantman = giantman_create();
    int8_t status = GIANTMAN_OK;

    if (giantman == NULL)
        return return_with_error(giantman, 2);
    if (argc == 2 && !my_strcmp(argv[1], "-h"))
        return return_with_help(giantman, argv[0]);
    if (argc != 3)
        return return_with_error(giantman, 0);
    giantman_set_file(giantman, argv[1]);
    if (parse_file_type(giantman, argv[2]))
        return_with_error(giantman, 1);
    status = giantman_uncompress(giantman);
    giantman_destroy(giantman);
    return status;
}
