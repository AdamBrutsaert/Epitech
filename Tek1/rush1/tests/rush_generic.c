/*
** EPITECH PROJECT, 2022
** rush_generic
** File description:
** Implementation of rush_generic
*/

#include <unistd.h>

extern void my_putchar(char c);

static void print_middle_line(int x, char *symbols)
{
    char c = ' ';

    for (int i = 0; i < x; i++) {
        if (i == 0 || i == x - 1)
            c = symbols[1];
        my_putchar(c);
        c = ' ';
    }
    my_putchar('\n');
}

static void print_horizontal_top(int x, int y, char *symbols)
{
    char c = symbols[0];

    for (int i = 0; i < x; i++) {
        if (i == 0 && y > 1 && x > 1)
            c = symbols[2];
        if (i == x - 1 && y > 1 && x > 1)
            c = symbols[3];
        my_putchar(c);
        c = symbols[0];
    }
    my_putchar('\n');
}

static void print_horizontal_bottom(int x, char *symbols)
{
    char c = symbols[0];

    for (int i = 0; i < x; i++) {
        if (i == 0 && x > 1)
            c = symbols[4];
        if (i == x - 1 && x > 1)
            c = symbols[5];
        my_putchar(c);
        c = symbols[0];
    }
    my_putchar('\n');
}

// symbols = "<horizontal-character><vertical-character>
//            <topleft><topright><botleft><botright>"
void rush_generic(int x, int y, char *symbols)
{
    if (x <= 0 || y <= 0) {
        write(2, "Invalid size\n", 14);
        return;
    }
    print_horizontal_top(x, y, symbols);
    for (int i = 0; i < y - 2; i++)
        print_middle_line(x, symbols);
    if (y > 1)
        print_horizontal_bottom(x, symbols);
}
