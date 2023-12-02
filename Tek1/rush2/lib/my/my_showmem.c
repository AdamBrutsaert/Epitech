/*
** EPITECH PROJECT, 2022
** my_showmem
** File description:
** Implementation of my_showmem
*/

extern void my_putchar(char c);
extern void my_putnbr_base(int nbr, char const *base);

static void print_adress(unsigned int line)
{
    static unsigned int const powers[8] = {
        1, 10, 100, 1000, 10000, 100000, 1000000, 10000000
    };

    line *= 10;
    for (int i = 7; i >= 0; i--) {
        my_putchar('0' + line / powers[i]);
        line %= powers[i];
    }
    my_putchar(':');
    my_putchar(' ');
}

static void print_hex(char const *str, unsigned int count)
{
    unsigned int i = 0;

    for (; i < count; i++) {
        if (str[i] < 16)
            my_putchar('0');
        my_putnbr_base((int)str[i], "0123456789abcdef");
        if (i != 0 && i % 2 == 1)
            my_putchar(' ');
    }
    for (; i < 16; i++) {
        my_putchar(' ');
        my_putchar(' ');
        if (i % 2 == 1)
            my_putchar(' ');
    }
}

static void print_char(char const *str, unsigned int count)
{
    for (unsigned int i = 0; i < count; i++)
        my_putchar(str[i] < 32 ? '.' : str[i]);
}

int my_showmem(char const *str, int size)
{
    unsigned int lines = size / 16 + !!(size % 16);

    for (unsigned int i = 0; i < lines; i++) {
        print_adress(i);
        print_hex(str + i * 16, (i != lines - 1) ? 16 : size % 16);
        print_char(str + i * 16, (i != lines - 1) ? 16 : size % 16);
        my_putchar('\n');
    }
    return 0;
}
