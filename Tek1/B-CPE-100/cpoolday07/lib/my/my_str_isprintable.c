/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** Implementation of my_str_isprintable
*/

int my_str_isprintable(char const *str)
{
    for (; *str; str++) {
        if (*str < 32)
            return 0;
    }
    return 1;
}
