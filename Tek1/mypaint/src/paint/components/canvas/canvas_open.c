/*
** EPITECH PROJECT, 2023
** canvas_open.c
** File description:
** canvas_open.c
*/

#include "private/paint/components/canvas.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static bool resize(canvas_t *canvas, sfVector2u size)
{
    sfRenderTexture *texture = sfRenderTexture_create(size.x, size.y, sfFalse);

    if (!texture)
        return false;
    sfRenderTexture_destroy(canvas->texture);
    canvas->texture = texture;
    sfSprite_setTexture(canvas->sprite, sfRenderTexture_getTexture(texture),
        sfTrue);
    return true;
}

static void draw_texture(canvas_t *canvas, sfTexture *texture)
{
    sfSprite *sprite = sfSprite_create();

    if (!sprite)
        return;
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderTexture_drawSprite(canvas->texture, sprite, NULL);
    sfSprite_destroy(sprite);
}

static void open(canvas_t *canvas, char const *file)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);

    if (!texture)
        return;
    if (!resize(canvas, sfTexture_getSize(texture)))
        return;
    draw_texture(canvas, texture);
    sfTexture_destroy(texture);
}

static void clean_string(char *str)
{
    for (size_t i = 0; str[i]; i++) {
        if (str[i] == '\n') {
            str[i] = '\0';
            return;
        }
    }
}

void canvas_open(canvas_t *canvas)
{
    char *filename = NULL;
    size_t len = 0;

    write(STDOUT_FILENO, "Enter which file you'd like to open: ", 37);
    if (getline(&filename, &len, stdin) == -1)
        return;
    clean_string(filename);
    open(canvas, filename);
    free(filename);
}
