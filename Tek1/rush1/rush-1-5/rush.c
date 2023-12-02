/*
** EPITECH PROJECT, 2022
** rush-1-5
** File description:
** Implementation of rush-1-5
*/

#include <unistd.h>

extern void my_putchar(char c);

static void print_middle_line(int x)
{
    char c = ' ';

    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1)
            c = 'B';
        my_putchar(c);
        c = ' ';
    }
    my_putchar('\n');
}

static void print_horizontal_top(int x, int y)
{
    char c = 'B';

    for (int i = 0; i < x; i++) {
        if (i == 0 && y > 1 && x > 1)
            c = 'A';
        if (i == x - 1 && y > 1 && x > 1)
            c = 'C';
        my_putchar(c);
        c = 'B';
    }
    my_putchar('\n');
}

static void print_horizontal_bottom(int x)
{
    char c = 'B';

    for (int i = 0; i < x; i++) {
        if (i == 0 && x > 1)
            c = 'C';
        if (i == x - 1 && x > 1)
            c = 'A';
        my_putchar(c);
        c = 'B';
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 13);
        return;
    }
    print_horizontal_top(x, y);
    for (int i = 0; i < y - 2; i++)
        print_middle_line(x);
    if (y > 1)
        print_horizontal_bottom(x);
}
