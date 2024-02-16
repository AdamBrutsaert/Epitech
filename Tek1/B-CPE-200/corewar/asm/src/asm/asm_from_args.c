/*
** EPITECH PROJECT, 2023
** asm_from_args.c
** File description:
** asm_from_args.c
*/

#include "asm_impl.h"
#include "my/string.h"

static int asm_run(char *file)
{
    asm_t *asm = asm_new();

    if (!asm_process(asm, file)) {
        asm_delete(asm);
        return 84;
    }
    asm_delete(asm);
    return 0;
}

int asm_from_args(int argc, char **argv)
{
    if (argc != 2)
        return 84;
    if (!my_strcmp(argv[1], "-h")) {
        asm_help(argv[0]);
        return 0;
    }
    return asm_run(argv[1]);
}
