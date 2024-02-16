/*
** EPITECH PROJECT, 2022
** my_str_islower
** File description:
** Implementation of my_str_islower
*/

int my_str_islower(char const *str)
{
    for (; *str; str++) {
        if (*str < 'a' || *str > 'z')
            return 0;
    }
    return 1;
}
