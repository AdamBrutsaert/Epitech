/*
** EPITECH PROJECT, 2022
** my_strcapitalize
** File description:
** Implementation of my_strcapitalize
*/

extern char *my_strlowcase(char *str);

static char is_not_alphanumerical(char c)
{
    if (c >= '0' && c <= '9')
        return 0;
    if (c >= 'a' && c <= 'z')
        return 0;
    if (c >= 'A' && c <= 'Z')
        return 0;
    return 1;
}

char *my_strcapitalize(char *str)
{
    char capitalize = 1;

    my_strlowcase(str);
    for (char *it = str; *it; it++) {
        *it -= (capitalize && *it >= 'a' && *it <= 'z') * 32;
        capitalize = is_not_alphanumerical(*it);
    }
    return str;
}
