/*
** EPITECH PROJECT, 2022
** my_lowcase
** File description:
** Implementation of my_lowcase
*/

char *my_strlowcase(char *str)
{
    for (char *it = str; *it; it++)
        *it += (*it >= 'A' && *it <= 'Z') * 32;
    return str;
}
