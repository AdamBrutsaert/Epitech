/*
** EPITECH PROJECT, 2022
** my_print_digits
** File description:
** Implementation of my_print_digits
*/

extern void my_putchar(char c);

int my_print_digits(void)
{
    for (char c = '0'; c <= '9'; c++)
        my_putchar(c);
    return 0;
}
