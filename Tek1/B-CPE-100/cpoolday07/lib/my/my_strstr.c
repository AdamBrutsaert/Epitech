/*
** EPITECH PROJECT, 2022
** my_strstr
** File description:
** Implementation of my_strstr
*/

static char match(char *str, char const *to_find)
{
    for (unsigned int i = 0; to_find[i]; i++) {
        if (str[i] != to_find[i])
            return 0;
    }
    return 1;
}

char *my_strstr(char *str, char const *to_find)
{
    for (; *str; str++) {
        if (match(str, to_find))
            return str;
    }
    return 0;
}
