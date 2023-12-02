/*
** EPITECH PROJECT, 2022
** my_strncmp
** File description:
** Implementation of my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    while (*s1 && *s2) {
        if (!n || *s1 != *s2)
            break;
        s1++;
        s2++;
        n--;
    }
    return !!n * ((unsigned char)(*s1) - (unsigned char)(*s2));
}
