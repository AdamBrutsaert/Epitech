/*
** EPITECH PROJECT, 2022
** print_middle
** File description:
** Implementation of print_middle
*/

extern void my_putchar(char c);
extern void my_print_n(char c, unsigned int n);

void print_middle(unsigned int size)
{
    for (unsigned int i = 0; i < size; i++) {
        my_print_n(' ', i + 1);
        my_putchar('*');
        my_print_n(' ', 6 * size - 2 * i - 5 + (size == 1) * 2);
        my_putchar('*');
        my_putchar('\n');
    }
    for (unsigned int i = 1; i < size; i++) {
        my_print_n(' ', size - i);
        my_putchar('*');
        my_print_n(' ',4 * size + 2 * i - 3 + (size == 1) * 2);
        my_putchar('*');
        my_putchar('\n');
    }
}
