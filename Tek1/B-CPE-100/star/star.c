/*
** EPITECH PROJECT, 2022
** star
** File description:
** Implementation of star
*/

extern void print_top(unsigned int size);
extern void print_horizontal(unsigned int size);
extern void print_middle(unsigned int size);
extern void print_bottom(unsigned int size);

void star(unsigned int size)
{
    if (size == 0)
        return;
    print_top(size);
    print_horizontal(size);
    print_middle(size);
    print_horizontal(size);
    print_bottom(size);
}
