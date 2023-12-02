/*
** EPITECH PROJECT, 2022
** tests_my_put_nbr
** File description:
** Implementation of tests_my_put_nbr
*/

extern void my_putchar(char c);
extern int my_put_nbr(int nb);

int main(void)
{
    my_put_nbr(-1);
    my_putchar('\n');
    my_put_nbr(0);
    my_putchar('\n');
    my_put_nbr(1);
    my_putchar('\n');
    my_put_nbr(-42);
    my_putchar('\n');
    my_put_nbr(42);
    my_putchar('\n');
    my_put_nbr(2147483647);
    my_putchar('\n');
    my_put_nbr(-2147483648);
    my_putchar('\n');
    return 0;
}
