/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** Implementation of my_sort_int_array
*/

extern void my_swap(int *a, int *b);

static unsigned int partition(int *array, unsigned int begin, unsigned int end)
{
    unsigned int j = begin;

    for (unsigned int i = begin; i < end; i++) {
        if (array[i] < array[end]) {
            my_swap(&array[i], &array[j]);
            j++;
        }
    }
    my_swap(&array[end], &array[j]);
    return j;
}

static void quicksort(int *array, int begin, int end)
{
    if (begin < end) {
        unsigned int pivot = partition(array, begin, end);
        quicksort(array, begin, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

void my_sort_int_array(int *array, int size)
{
    quicksort(array, 0, size - 1);
}
