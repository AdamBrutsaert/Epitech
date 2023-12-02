/*
** EPITECH PROJECT, 2022
** my_str_isupper
** File description:
** Implementation of my_str_isupper
*/

int my_str_isupper(char const *str)
{
    for (; *str; str++) {
        if (*str < 'A' || *str > 'Z')
            return 0;
    }
    return 1;
}
