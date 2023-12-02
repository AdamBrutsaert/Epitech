/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** Implementation of my_strlen
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length])
        length++;
    return length;
}
