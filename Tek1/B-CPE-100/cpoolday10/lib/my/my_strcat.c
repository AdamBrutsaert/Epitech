/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** Implementatio of my_strcat
*/

extern int my_strlen(char const *str);
extern char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *dest, char const *src)
{
    my_strcpy(dest + my_strlen(dest), src);
    return dest;
}
