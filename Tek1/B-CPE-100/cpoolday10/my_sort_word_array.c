/*
** EPITECH PROJECT, 2022
** my_sort_word_array
** File description:
** Implementation of my_sort_word_array
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

static int get_array_length(char **array)
{
    int length = 0;

    while (array[length])
        length++;
    return length;
}

int my_sort_word_array(char **tab)
{
    quicksort(tab, 0, get_array_length(tab) - 1);
    return 0;
}
