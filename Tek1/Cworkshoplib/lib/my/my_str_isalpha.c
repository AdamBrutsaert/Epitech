/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** Implementation of my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    for (; *str; str++) {
        if ((*str < 'A' || *str > 'Z') && (*str < 'a' || *str > 'z'))
            return 0;
    }
    return 1;
}
