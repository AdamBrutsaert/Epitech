/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** Implementation of my_swap
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
