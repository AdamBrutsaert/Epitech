/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** Implementation of my_print_revalpha
*/

extern void my_putchar(char c);

int my_print_revalpha(void)
{
    for (char c = 'z'; c >= 'a'; c--)
        my_putchar(c);
    return 0;
}
