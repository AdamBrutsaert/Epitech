/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** Implementation of my_getnbr
*/

// Overflow is checked by verifying that the number hasn't changed sign.
// That is because when multiplying by 10 and adding a number between 0
// and 9 will every time change the sign if an overflow occurs.
int my_getnbr(char const *str)
{
    char sign = 1;
    int number = 0;

    for (; *str == '+' || *str == '-'; str++) {
        if (*str == '-')
            sign *= -1;
    }
    for (; *str >= '0' && *str <= '9'; str++) {
        number = number * 10 + sign * (*str - '0');
        if ((sign == 1 && number < 0) || (sign == -1 && number > 0))
            return 0;
    }
    return number;
}
