/*
** EPITECH PROJECT, 2022
** pushswap_parser_sort.c
** File description:
** pushswap_parser_sort.c
*/

#include "pushswap/pushswap_parser.h"
#include "my/memory.h"

static void swap_number_ptr(number_t **a, number_t **b)
{
    number_t *tmp;

    my_memcpy(&tmp, a, sizeof(number_t *));
    my_memcpy(a, b, sizeof(number_t *));
    my_memcpy(b, &tmp, sizeof(number_t *));
}

static i64_t partition(number_t **array, i64_t begin, i64_t end)
{
    i64_t j = begin;

    for (i64_t i = begin; i < end; i++) {
        if (array[i]->value < array[end]->value) {
            swap_number_ptr(&array[i], &array[j]);
            j++;
        }
    }
    swap_number_ptr(&array[end], &array[j]);
    return j;
}

static void quicksort(number_t **array, i64_t begin, i64_t end)
{
    i64_t pivot;

    if (begin < end) {
        pivot = partition(array, begin, end);
        quicksort(array, begin, pivot - 1);
        quicksort(array, pivot + 1, end);
    }
}

void pushswap_parser_sort(pushswap_parser_t *parser)
{
    quicksort(parser->sorted.values, 0, parser->sorted.length - 1);
}
