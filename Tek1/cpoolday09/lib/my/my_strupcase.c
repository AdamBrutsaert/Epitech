/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** Implementation of my_strupcase
*/

char *my_strupcase(char *str)
{
    for (char *it = str; *it; it++)
        *it -= (*it >= 'a' && *it <= 'z') * 32;
    return str;
}
