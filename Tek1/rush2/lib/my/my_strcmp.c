/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** Implementation of my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1 && *s2) {
        if (*s1 != *s2)
            break;
        s1++;
        s2++;
    }
    return (unsigned char)(*s1) - (unsigned char)(*s2);
}
