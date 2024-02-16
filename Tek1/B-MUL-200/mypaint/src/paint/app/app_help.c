/*
** EPITECH PROJECT, 2023
** app_help.c
** File description:
** app_help.c
*/

#include "private/paint/app.h"

#include <unistd.h>

static void print(char const *string)
{
    uint64_t len = 0;

    while (string[len])
        len++;
    write(STDOUT_FILENO, string, len);
}

bool app_help(void)
{
    print("MyPaint\n\n");
    print("Tools:\n");
    print("    Pencil: Click and drag to draw.\n");
    print("    Eraser: Click and drag to erase.\n");
    print("    Hand: Click and drag to move the canvas.\n\n");
    print("    For the pencil and eraser, you can change the size and "
        "shape.\n\n");
    print("Shorcuts:\n");
    print("    Press P to select the pencil tool.\n");
    print("    Press E to select the eraser tool.\n");
    print("    Press H to select the hand tool.\n");
    return true;
}
