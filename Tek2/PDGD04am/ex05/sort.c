/*
** EPITECH PROJECT, 2024
** sort.c
** File description:
** sort.c
*/

#include <stdlib.h>
#include <stdbool.h>

static int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void sort_int_array(int *array, size_t nmemb)
{
    qsort(array, nmemb, sizeof(int), compare);
}

void sort_array(
    void *array,
    size_t nmemb,
    size_t size,
    int (*compar)(const void *, const void *)
)
{
    qsort(array, nmemb, size, compar);
}
