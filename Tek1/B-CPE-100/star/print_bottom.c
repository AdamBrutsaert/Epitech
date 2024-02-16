/*
** EPITECH PROJECT, 2022
** print_bottom
** File description:
** Implementation of print_bottom
*/

extern void my_putchar(char c);
extern void my_print_n(char c, unsigned int n);

void print_bottom(unsigned int size)
{
    unsigned int offset = 3 * size - 1 + (size == 1);

    for (unsigned int i = 1; i < size; i++) {
        my_print_n(' ', offset - (size - i));
        my_putchar('*');
        my_print_n(' ', 2 * (size - i) - 1);
        my_putchar('*');
        my_putchar('\n');
    }
    my_print_n(' ', offset);
    my_putchar('*');
    my_putchar('\n');
}
