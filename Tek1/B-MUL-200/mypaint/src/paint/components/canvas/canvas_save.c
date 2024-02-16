/*
** EPITECH PROJECT, 2023
** canvas_save.c
** File description:
** canvas_save.c
*/

#include "private/paint/components/canvas.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void clean_string(char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
}

void canvas_save(canvas_t *canvas)
{
    sfImage *image =
        sfTexture_copyToImage(sfRenderTexture_getTexture(canvas->texture));
    char *name = NULL;
    size_t size = 0;

    if (!image)
        return;
    write(STDOUT_FILENO, "How would you like to name the file: ", 37);
    if (getline(&name, &size, stdin) == -1) {
        sfImage_destroy(image);
        return;
    }
    clean_string(name);
    sfImage_saveToFile(image, name);
    sfImage_destroy(image);
    free(name);
}
