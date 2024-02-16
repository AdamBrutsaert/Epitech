/*
** EPITECH PROJECT, 2022
** my_strncat
** File description:
** Implementatio of my_strncat
*/

extern int my_strlen(char const *str);
extern char *my_strncpy(char *dest, char const *src, int n);

char *my_strncat(char *dest, char const *src, int nb)
{
    my_strncpy(dest + my_strlen(dest), src, nb);
    return dest;
}
