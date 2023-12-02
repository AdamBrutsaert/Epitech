/*
** EPITECH PROJECT, 2022
** my_print_comb2
** File description:
** Implementation of my_print_comb2
*/

extern void my_putchar(char c);

static void print_number(char n)
{
    my_putchar('0' + n / 10);
    my_putchar('0' + n % 10);
}

static void print_separator(char i, char j)
{
    if (i != 98 || j != 99) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    for (char i = 0; i <= 98; i++) {
        for (char j = i + 1; j <= 99; j++) {
            print_number(i);
            my_putchar(' ');
            print_number(j);
            print_separator(i, j);
        }
    }
    return 0;
}
