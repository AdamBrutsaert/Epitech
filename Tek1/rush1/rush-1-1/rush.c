/*
** EPITECH PROJECT, 2022
** rush-1-1
** File description:
** Implementation of rush-1-1
*/

#include <unistd.h>

extern void my_putchar(char c);

static void print_middle_line(int x)
{
    char c = ' ';

    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1)
            c = '|';
        my_putchar(c);
        c = ' ';
    }
    my_putchar('\n');
}

static void print_horizontal_line(int x)
{
    char c = '-';

    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1)
            c = 'o';
        my_putchar(c);
        c = '-';
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    print_horizontal_line(x);
    for (int i = 0; i < y - 2; i++)
        print_middle_line(x);
    if (y > 1)
        print_horizontal_line(x);
}
