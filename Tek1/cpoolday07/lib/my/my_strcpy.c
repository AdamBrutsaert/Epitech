/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** Implementation of my_strcpy
*/

char *my_strcpy(char *dest, char const *src)
{
    unsigned int i = 0;

    for (; src[i]; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
