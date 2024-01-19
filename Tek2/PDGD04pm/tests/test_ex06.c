/*
** EPITECH PROJECT, 2024
** test_ex05.c
** File description:
** test_ex05.c
*/

#include "queue.h"
#include "utils.h"

#include <criterion/criterion.h>

Test(queue_get_size, empty_queue)
{
    cr_assert_eq(queue_get_size(NULL), 0);
}

Test(queue_get_size, two_nodes)
{
    queue_t *queue = NULL;

    cr_expect(queue_push(&queue, (void *)0x1));
    cr_expect(queue_push(&queue, (void *)0x2));

    cr_assert_eq(queue_get_size(queue), 2);
}


Test(queue_is_empty, empty_queue)
{
    cr_assert(queue_is_empty(NULL));
}

Test(queue_is_empty, one_node)
{
    queue_t *queue = NULL;

    cr_expect(queue_push(&queue, NULL));

    cr_assert_not(queue_is_empty(queue));
}

Test(queue_push, three_push)
{
    queue_t *queue = NULL;

    cr_assert(queue_push(&queue, (void *)0x1));
    cr_assert(queue_push(&queue, (void *)0x2));
    cr_assert(queue_push(&queue, (void *)0x3));
    cr_assert(compare_list(queue, (void *[]){(void *)0x1, (void *)0x2, (void *)0x3}, 3));
}

Test(queue_pop, three_nodes)
{
    queue_t *queue = NULL;

    cr_expect(queue_push(&queue, (void *)0x1));
    cr_expect(queue_push(&queue, (void *)0x2));
    cr_expect(queue_push(&queue, (void *)0x3));

    cr_assert(queue_pop(&queue));
    cr_assert(compare_list(queue, (void *[]){(void *)0x2, (void *)0x3}, 2));

    cr_assert(queue_pop(&queue));
    cr_assert(compare_list(queue, (void *[]){(void *)0x3}, 1));

    cr_assert(queue_pop(&queue));
    cr_assert(compare_list(queue, (void *[]){}, 0));

    cr_assert_not(queue_pop(&queue));
}


Test(queue_clear, three_nodes)
{
    queue_t *queue = NULL;

    cr_expect(queue_push(&queue, (void *)0x1));
    cr_expect(queue_push(&queue, (void *)0x2));
    cr_expect(queue_push(&queue, (void *)0x3));

    cr_expect_not_null(queue);
    queue_clear(&queue);

    cr_assert_null(queue);
}

Test(queue_clear, empty_queue)
{
    queue_t *queue = NULL;

    queue_clear(&queue);
    cr_assert_null(queue);
}

Test(queue_front, three_nodes)
{
    queue_t *queue = NULL;

    cr_expect(queue_push(&queue, (void *)0x1));
    cr_expect(queue_push(&queue, (void *)0x2));
    cr_expect(queue_push(&queue, (void *)0x3));

    cr_assert_eq(queue_front(queue), (void *)0x1);
}

Test(queue_front, empty_queue)
{
    cr_assert_eq(queue_front(NULL), NULL);
}
