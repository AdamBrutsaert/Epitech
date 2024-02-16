/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** Implementation of my_putstr
*/

extern void my_putchar(char c);

int my_putstr(char const *str)
{
    for (; *str; str++)
        my_putchar(*str);
    return 0;
}
