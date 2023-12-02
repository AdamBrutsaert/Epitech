/*
** EPITECH PROJECT, 2023
** save_read.c
** File description:
** save_read.c
*/

#include "save_impl.h"
#include "my/stdio.h"

#include <stdlib.h>

void save_read(void)
{
    char *content = read_file(SAVE_FILE);
    char *copy = content;
    char buffer;

    if (content == NULL)
        return save_default();
    if (!save_read_u32(&content, &STATE.has_red_pot)) {
        free(copy);
        return save_default();
    }
    if (!save_read_char(&content, &buffer)) {
        free(copy);
        return save_default();
    }
    if (!save_read_u32(&content, &STATE.has_blue_pot)) {
        free(copy);
        return save_default();
    }
    free(copy);
}
