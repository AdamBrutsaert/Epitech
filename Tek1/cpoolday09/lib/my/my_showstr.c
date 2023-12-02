/*
** EPITECH PROJECT, 2022
** my_showstr
** File description:
** Implementation of my_showstr
*/

extern void my_putchar(char c);
extern int my_putnbr_base(int nbr, char const *base);

static void print_non_printable(char c)
{
    my_putchar('\\');
    if (c < 16)
        my_putchar('0');
    my_putnbr_base((int)c, "0123456789abcdef");
}

int my_showstr(char const *str)
{
    for (; *str; str++) {
        if (*str < 32) {
            print_non_printable(*str);
        } else {
            my_putchar(*str);
        }
    }
}
