/*
** EPITECH PROJECT, 2022
** file_vector_sort.c
** File description:
** file_vector_sort.c
*/

#include "my/details/file.h"
#include "my/memory.h"

static void swap_files(file_t *f1, file_t *f2)
{
    file_t temp;

    my_memcpy(&temp, f1, sizeof(file_t));
    my_memcpy(f1, f2, sizeof(file_t));
    my_memcpy(f2, &temp, sizeof(file_t));
}

static unsigned int partition(file_t *array, unsigned int begin,
    unsigned int end, int (*cmp)(file_t *, file_t *))
{
    unsigned int j = begin;

    for (unsigned int i = begin; i < end; i++) {
        if (cmp(&array[i], &array[end]) < 0) {
            swap_files(&array[i], &array[j]);
            j++;
        }
    }
    swap_files(&array[end], &array[j]);
    return j;
}

static void quicksort(file_t *array, int begin, int end,
    int (*cmp)(file_t *, file_t *))
{
    if (begin < end) {
        unsigned int pivot = partition(array, begin, end, cmp);
        quicksort(array, begin, pivot - 1, cmp);
        quicksort(array, pivot + 1, end, cmp);
    }
}

void file_vector_sort(file_vector_t *files, int8_t by_time, int8_t reverse)
{
    if (!by_time && !reverse)
        quicksort(files->files, 0, files->length - 1, file_cmp_name);
    if (!by_time && reverse)
        quicksort(files->files, 0, files->length - 1, file_cmp_rev_name);
    if (by_time && !reverse)
        quicksort(files->files, 0, files->length - 1, file_cmp_timestamp);
    if (by_time && reverse)
        quicksort(files->files, 0, files->length - 1, file_cmp_rev_timestamp);
}
