/*
** EPITECH PROJECT, 2022
** printing
** File description:
** Implementation of printing
*/

#include "my.h"

extern unsigned int count_occurences(char const *str, char c);
extern float calculate_percentage(char const *str, char c);

void print_float(float a)
{
    my_put_nbr((int)a);
    my_putchar('.');
    my_put_nbr((int)(a * 10) % 10);
    my_put_nbr((int)(a * 100) % 10);
}

void print_line(char const *str, char c)
{
    unsigned int count = count_occurences(str, c);
    float percentage = calculate_percentage(str, c);

    my_putchar(c);
    my_putchar(':');
    my_put_nbr(count);
    my_putstr(" (");
    print_float(percentage);
    my_putstr("%)\n");
}

void print_result(float en, float fr, float ge, float es)
{
    if (en <= fr && en <= ge && en <= es) {
        my_putstr("=> English");
        return;
    }
    if (fr <= en && fr <= ge && fr <= es) {
        my_putstr("=> French");
        return;
    }
    if (ge <= fr && ge <= en && ge <= es) {
        my_putstr("=> German");
        return;
    }
    my_putstr("=> Spanish");
}
