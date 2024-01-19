/*
** EPITECH PROJECT, 2024
** uniq.c
** File description:
** uniq.c
*/

#include <stddef.h>
#include <stdbool.h>
#include <string.h>

static bool int_contains(int *array, size_t nth)
{
    int value = array[nth];

    for (size_t i = 0; i < nth; i++) {
        if (array[i] == value)
            return true;
    }
    return false;
}

size_t uniq_int_array(int *array, size_t nmemb)
{
    size_t new_length = nmemb;

    for (size_t i = 1; i < new_length; i++) {
        if (int_contains(array, i)) {
            new_length--;
            memmove(&array[i], &array[i + 1], (new_length - i) * sizeof(int));
            i--;
        }
    }
    return new_length;
}

static bool void_contains(
    void *array,
    size_t size,
    int (*compar)(const void *, const void *),
    size_t nth
)
{
    const void *value = (char *)array + nth * size;

    for (size_t i = 0; i < nth; i++) {
        if (compar(value, (char *)array + i * size) == 0)
            return true;
    }
    return false;
}

size_t uniq_array(
    void *array,
    size_t nmemb,
    size_t size,
    int (*compar)(const void *, const void *)
)
{
    size_t new_length = nmemb;

    for (size_t i = 1; i < new_length; i++) {
        if (void_contains(array, size, compar, i)) {
            new_length--;
            memmove(
                (char *)array + i * size,
                (char *)array + (i + 1) * size,
                (new_length - i) * size
            );
            i--;
        }
    }
    return new_length;
}
