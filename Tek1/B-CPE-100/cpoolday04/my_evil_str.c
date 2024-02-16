/*
** EPITECH PROJECT, 2022
** my_evil_str
** File description:
** Implementation of my_evil_str
*/

extern int my_strlen(char const *str);

static void swap_char(char *a, char *b)
{
    char temp = *a;

    *a = *b;
    *b = temp;
}

char *my_evil_str(char *str)
{
    int length = my_strlen(str);

    for (int i = 0; i < length / 2; i++)
        swap_char(&str[i], &str[length - i - 1]);
    return str;
}
