/*
** EPITECH PROJECT, 2022
** my_getnbr_base
** File description:
** Implementation of my_getnbr_base
*/

extern int my_strlen(char const *str);
extern int check_mult(int a, int b, char *overflow);
extern int check_add(int a, int b, char *overflow);

static int get_index(char c, char const *string)
{
    for (unsigned int i = 0; string[i]; i++) {
        if (c == string[i])
            return i;
    }
    return -1;
}

int my_getnbr_base(char const *str, char const *base)
{
    char sign = 1;
    int number = 0;
    char overflow = 0;
    int length = my_strlen(base);

    if (length < 2)
        return 0;
    for (; *str == '+' || *str == '-'; str++) {
        if (*str == '-')
            sign *= -1;
    }
    for (; get_index(*str, base) != -1; str++) {
        number = check_mult(number, length, &overflow);
        number = check_add(number, sign * get_index(*str, base), &overflow);
        if (overflow)
            return 0;
    }
    return number;
}
