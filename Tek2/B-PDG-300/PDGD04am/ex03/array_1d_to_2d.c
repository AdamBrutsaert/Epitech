/*
** EPITECH PROJECT, 2024
** array_1d_to_2d.c
** File description:
** array_1d_to_2d.c
*/

#include <stdlib.h>
#include <string.h>

static void fill_non_null_res(
    const int *array,
    size_t height,
    size_t width,
    int ***res
)
{
    for (size_t i = 0; i < height; i++) {
        (*res)[i] = calloc(sizeof(int), width);
        if ((*res)[i] != NULL)
            memcpy((*res)[i], &array[i * width], sizeof(int) * width);
    }
}

void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res)
{
    *res = calloc(sizeof(int *), height);
    if (*res != NULL)
        fill_non_null_res(array, height, width, res);
}

void array_2d_free(
    int **array,
    size_t height,
    __attribute__((unused)) size_t width
)
{
    for (size_t i = 0; i < height; i++)
        free(array[i]);
    free(array);
}
