/*
** EPITECH PROJECT, 2022
** my_print_comb
** File description:
** Implementation of my_print_comb
*/

extern void my_putchar(char c);

static void inner_loop(char i, char j)
{
    for (char k = j + 1; k <= '9'; k++) {
        my_putchar(i);
        my_putchar(j);
        my_putchar(k);

        if (i != '7' || j != '8') {
            my_putchar(',');
            my_putchar(' ');
        }
    }
}

int my_print_comb(void)
{
    for (char i = '0'; i <= '7'; i++) {
        for (char j = i + 1; j <= '8'; j++) {
            inner_loop(i, j);
        }
    }
    return 0;
}
