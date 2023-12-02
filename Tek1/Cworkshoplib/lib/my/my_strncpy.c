/*
** EPITECH PROJECT, 2022
** my_strncpy
** File description:
** Implementation of my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (; i < n && src[i]; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
