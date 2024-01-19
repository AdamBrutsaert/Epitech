/*
** EPITECH PROJECT, 2024
** disp.c
** File description:
** disp.c
*/

#include <stdio.h>

void disp_int_array(const int *array, size_t nmemb)
{
    for (size_t i = 0; i < nmemb; i++)
        printf("%d\n", array[i]);
}

void disp_array(
    const void *array,
    size_t nmemb,
    size_t size,
    void (*print)(const void *)
)
{
    for (size_t i = 0; i < nmemb; i++)
        print((char *)array + i * size);
}
