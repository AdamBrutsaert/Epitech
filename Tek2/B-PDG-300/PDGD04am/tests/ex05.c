/*
** EPITECH PROJECT, 2024
** ex05.c
** File description:
** ex05.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

extern void sort_int_array(int *array, size_t nmemb);
extern size_t uniq_int_array(int *array, size_t nmemb);
extern void disp_int_array(const int *array, size_t nmemb);
extern void sort_array(void *array, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
size_t uniq_array(void *array, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
void disp_array(const void *array, size_t nmemb, size_t size, void (*print)(const void *));

Test(sort_int_array, test1)
{
    int array[] = { 10, -16, 21, 4, 9, -6 };

    sort_int_array(array, 6);
    cr_assert_arr_eq(array, ((int []){-16, -6, 4, 9, 10, 21 }), 6);
}

Test(sort_int_array, test2)
{
    int array[] = {};

    sort_int_array(array, 0);
    cr_assert_arr_eq(array, ((int []){}), 0);
}

Test(uniq_int_array, test1)
{
    int array[] = { 3, -1, 7, -1, 3, 3, 3, 10, 5};

    cr_assert_eq(uniq_int_array(array, 9), 5);
    cr_assert_arr_eq(array, ((int []){3, -1, 7, 10, 5}), 5);
}

Test(uniq_int_array, test2)
{
    int array[] = {};

    cr_assert_eq(uniq_int_array(array, 0), 0);
    cr_assert_arr_eq(array, ((int []){}), 0);
}

Test(uniq_int_array, test3)
{
    int array[] = {1, 2, 3, 4, 5};

    cr_assert_eq(uniq_int_array(array, 5), 5);
    cr_assert_arr_eq(array, ((int []){1, 2, 3, 4, 5}), 5);
}

Test(disp_int_array, test1, .init = cr_redirect_stdout)
{
    int array[] = { -5, 3, -10, 7 };

    disp_int_array(array, 4);
    fflush(stdout);
    cr_assert_stdout_eq_str("-5\n3\n-10\n7\n");
}

Test(disp_int_array, test2, .init = cr_redirect_stdout)
{
    int array[] = {};

    disp_int_array(array, 0);
    fflush(stdout);
    cr_assert_stdout_eq_str("");
}

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

Test(sort_array, test1)
{
    int array[] = { 10, -16, 21, 4, 9, -6 };

    sort_array(array, 6, sizeof(int), compare);
    cr_assert_arr_eq(array, ((int []){-16, -6, 4, 9, 10, 21 }), 6);
}

Test(sort_array, test2)
{
    int array[] = {};

    sort_array(array, 0, sizeof(int), compare);
    cr_assert_arr_eq(array, ((int []){}), 0);
}

Test(uniq_array, test1)
{
    int array[] = { 3, -1, 7, -1, 3, 3, 3, 10, 5};

    cr_assert_eq(uniq_array(array, 9, sizeof(int), compare), 5);
    cr_assert_arr_eq(array, ((int []){3, -1, 7, 10, 5}), 5);
}

Test(uniq_array, test2)
{
    int array[] = {};

    cr_assert_eq(uniq_array(array, 0, sizeof(int), compare), 0);
    cr_assert_arr_eq(array, ((int []){}), 0);
}

Test(uniq_array, test3)
{
    int array[] = {1, 2, 3, 4, 5};

    cr_assert_eq(uniq_array(array, 5, sizeof(int), compare), 5);
    cr_assert_arr_eq(array, ((int []){1, 2, 3, 4, 5}), 5);
}

void print(const void *param)
{
    printf("%d\n", *(int *)param);
}

Test(disp_array, test1, .init = cr_redirect_stdout)
{
    int array[] = {1, 2, 3, 4, 5};

    disp_array(array, 5, sizeof(int), print);
    fflush(stdout);
    cr_assert_stdout_eq_str("1\n2\n3\n4\n5\n");
}
