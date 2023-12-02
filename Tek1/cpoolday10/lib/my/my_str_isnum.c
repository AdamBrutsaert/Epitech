/*
** EPITECH PROJECT, 2022
** my_str_isnum
** File description:
** Implementation of my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (; *str; str++) {
        if (*str < '0' || *str > '9')
            return 0;
    }
    return 1;
}
