/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** Implementation of my_print_alpha
*/

extern void my_putchar(char c);

int my_print_alpha(void)
{
    for (char c = 'a'; c <= 'z'; c++)
        my_putchar(c);
    return 0;
}
