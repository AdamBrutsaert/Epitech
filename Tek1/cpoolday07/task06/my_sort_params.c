/*
** EPITECH PROJECT, 2022
** my_sort_params
** File description:
** Implementation of my_sort_params
*/

#include "my.h"

static void swap_strings(char **s1, char **s2)
{
    char *temp = *s1;

    *s1 = *s2;
    *s2 = temp;
}

static unsigned int partition(char **a, unsigned int begin, unsigned int end)
{
    unsigned int j = begin;

    for (unsigned int i = begin; i < end; i++) {
        if (my_strcmp(a[i], a[end]) < 0) {
            swap_strings(&a[i], &a[j]);
            j++;
        }
    }
    swap_strings(&a[end], &a[j]);
    return j;
}

static void quicksort(char **array, int begin, int end)
{
    if (begin < end) {
        unsigned int pivot = partition(array, begin, end);
        quicksort(array, begin, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

int main(int argc, char **argv)
{
    quicksort(argv, 0, argc - 1);
    for (unsigned int i = 0; i < argc; i++) {
        my_putstr(argv[i]);
        my_putchar('\n');
    }
}
