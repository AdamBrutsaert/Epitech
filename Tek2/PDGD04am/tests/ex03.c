/*
** EPITECH PROJECT, 2024
** ex03.c
** File description:
** ex03.c
*/

#include <criterion/criterion.h>

extern void array_1d_to_2d(const int *array, size_t height, size_t width, int ***res);
extern void array_2d_free(int **array, size_t height, size_t width);

Test(array_1d_to_2d, test1)
{
    const int array[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int **res = NULL;

    array_1d_to_2d(array, 2, 4, &res);
    cr_expect_neq(res, NULL);
    cr_expect_neq(res[0], NULL);
    cr_assert_arr_eq(res[0], ((int []){1, 2, 3, 4}), 4);
    cr_expect_neq(res[1], NULL);
    cr_assert_arr_eq(res[1], ((int []){5, 6, 7, 8}), 4);
    array_2d_free(res, 2, 4);
}
