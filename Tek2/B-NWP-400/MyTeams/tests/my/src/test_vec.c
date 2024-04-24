/*
** EPITECH PROJECT, 2024
** test_vec.c
** File description:
** test_vec.c
*/

#include "my/memory/vec.h"

#include <criterion/criterion.h>

static bool vec_equals(vec_t *vec, int *expected, size_t length)
{
    int *data = VEC_DATA(vec);

    if (VEC_LEN(vec) != length)
        return false;
    for (size_t i = 0; i < length; i++) {
        if (data[i] != expected[i])
            return false;
    }
    return true;
}

Test(vec, init_deinit)
{
    vec_t *vec = vec_create(sizeof(int));

    cr_assert_eq(VEC_DATA(vec), NULL);
    cr_assert_eq(VEC_LEN(vec), 0);
    cr_assert_eq(VEC_CAP(vec), 0);
    cr_assert_eq(VEC_STRIDE(vec), sizeof(int));

    vec_destroy(vec);
}

Test(vec, reserve)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_reserve(vec, 0);
    cr_assert_eq(VEC_DATA(vec), NULL);
    cr_assert_eq(VEC_CAP(vec), 0);

    vec_reserve(vec, 10);
    cr_assert_neq(VEC_DATA(vec), NULL);
    cr_assert_eq(VEC_CAP(vec), 10);

    vec_reserve(vec, 5);
    cr_assert_neq(VEC_DATA(vec), NULL);
    cr_assert_eq(VEC_CAP(vec), 10);

    vec_destroy(vec);
}

Test(vec, reserve_at_least)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_reserve_at_least(vec, 0);
    cr_assert_eq(VEC_DATA(vec), NULL);
    cr_assert_eq(VEC_CAP(vec), 0);

    vec_reserve_at_least(vec,  10);
    cr_assert_neq(VEC_DATA(vec), NULL);
    cr_assert_geq(VEC_CAP(vec), 10);

    size_t capacity = VEC_CAP(vec);

    vec_reserve_at_least(vec, 5);
    cr_assert_neq(VEC_DATA(vec), NULL);
    cr_assert_geq(VEC_CAP(vec), capacity);

    vec_destroy(vec);
}

Test(vec, push_back)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back(vec, &(int){1});
    cr_assert(vec_equals(vec, (int[]){1}, 1));

    vec_push_back(vec, &(int){2});
    cr_assert(vec_equals(vec, (int[]){1, 2}, 2));

    vec_push_back_some(vec, &(int[]){3, 4}, 2);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_push_back_some(vec, &(int[]){}, 0);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_destroy(vec);
}

Test(vec, push_front)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_front(vec, &(int){1});
    cr_assert(vec_equals(vec, (int[]){1}, 1));

    vec_push_front(vec, &(int){2});
    cr_assert(vec_equals(vec, (int[]){2, 1}, 2));

    vec_push_front_some(vec, ((int[]){3, 4}), 2);
    cr_assert(vec_equals(vec, (int[]){3, 4, 2, 1}, 4));

    vec_push_front_some(vec, ((int[]){}), 0);
    cr_assert(vec_equals(vec, (int[]){3, 4, 2, 1}, 4));

    vec_destroy(vec);
}

Test(vec, at)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    cr_assert_eq(*(int *)VEC_AT(vec, 0), 1);
    cr_assert_eq(*(int *)VEC_AT(vec, 1), 2);
    cr_assert_eq(*(int *)VEC_AT(vec, 2), 3);
    cr_assert_eq(*(int *)VEC_AT(vec, 3), 4);

    vec_destroy(vec);
}

Test(vec, clear)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_clear(vec);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_clear(vec);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_destroy(vec);
}

Test(vec, pop_back)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_pop_back(vec);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3}, 3));

    vec_pop_some_back(vec, 2);
    cr_assert(vec_equals(vec, (int[]){1}, 1));

    vec_pop_some_back(vec, 2);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_pop_back(vec);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_destroy(vec);
}

Test(vec, pop_front)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_pop_front(vec);
    cr_assert(vec_equals(vec, (int[]){2, 3, 4}, 3));

    vec_pop_some_front(vec, 2);
    cr_assert(vec_equals(vec, (int[]){4}, 1));

    vec_pop_some_front(vec, 2);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_pop_front(vec);
    cr_assert(vec_equals(vec, (int[]){}, 0));

    vec_destroy(vec);
}

Test(vec, swap)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_swap(vec, 0, 3);
    cr_assert(vec_equals(vec, (int[]){4, 2, 3, 1}, 4));

    vec_swap(vec, 1, 2);
    cr_assert(vec_equals(vec, (int[]){4, 3, 2, 1}, 4));

    vec_swap(vec, 0, 0);
    cr_assert(vec_equals(vec, (int[]){4, 3, 2, 1}, 4));

    vec_swap(vec, 0, 4);
    cr_assert(vec_equals(vec, (int[]){4, 3, 2, 1}, 4));

    vec_swap(vec, 4, 0);
    cr_assert(vec_equals(vec, (int[]){4, 3, 2, 1}, 4));

    vec_swap(vec, 12, 24);
    cr_assert(vec_equals(vec, (int[]){4, 3, 2, 1}, 4));

    vec_destroy(vec);
}

Test(vec, insert)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_insert(vec, 0, &(int){0});
    cr_assert(vec_equals(vec, (int[]){0, 1, 2, 3, 4}, 5));

    vec_insert(vec, 2, &(int){5});
    cr_assert(vec_equals(vec, (int[]){0, 1, 5, 2, 3, 4}, 6));

    vec_insert(vec, 6, &(int){6});
    cr_assert(vec_equals(vec, (int[]){0, 1, 5, 2, 3, 4, 6}, 7));

    vec_insert(vec, 12, &(int){7});
    cr_assert(vec_equals(vec, (int[]){0, 1, 5, 2, 3, 4, 6, 7}, 8));

    vec_destroy(vec);
}

Test(vec, insert_slice)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_insert_some(vec, 0, ((int[]){0}), 1);
    cr_assert(vec_equals(vec, (int[]){0, 1, 2, 3, 4}, 5));

    vec_insert_some(vec, 2, ((int[]){5, 7}), 2);
    cr_assert(vec_equals(vec, (int[]){0, 1, 5, 7, 2, 3, 4}, 7));

    vec_insert_some(vec, 12, ((int[]){6, 9, 2}), 3);
    cr_assert(vec_equals(vec, (int[]){0, 1, 5, 7, 2, 3, 4, 6, 9, 2}, 10));

    vec_destroy(vec);
}

Test(vec, remove)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4}), 4);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4}, 4));

    vec_remove(vec, 0);
    cr_assert(vec_equals(vec, (int[]){2, 3, 4}, 3));

    vec_remove(vec, 1);
    cr_assert(vec_equals(vec, (int[]){2, 4}, 2));

    vec_remove(vec, 2);
    cr_assert(vec_equals(vec, (int[]){2, 4}, 2));

    vec_remove(vec, 12);
    cr_assert(vec_equals(vec, (int[]){2, 4}, 2));

    vec_destroy(vec);
}

Test(vec, remove_some)
{
    vec_t *vec = vec_create(sizeof(int));

    vec_push_back_some(vec, ((int[]){1, 2, 3, 4, 5, 6, 7, 8}), 8);
    cr_assert(vec_equals(vec, (int[]){1, 2, 3, 4, 5, 6, 7, 8}, 8));

    vec_remove_some(vec, 0, 2);
    cr_assert(vec_equals(vec, (int[]){3, 4, 5, 6, 7, 8}, 6));

    vec_remove_some(vec, 2, 2);
    cr_assert(vec_equals(vec, (int[]){3, 4, 7, 8}, 4));

    vec_remove_some(vec, 4, 2);
    cr_assert(vec_equals(vec, (int[]){3, 4, 7, 8}, 4));

    vec_remove_some(vec, 3, 5);
    cr_assert(vec_equals(vec, (int[]){3, 4, 7}, 3));

    vec_destroy(vec);
}
