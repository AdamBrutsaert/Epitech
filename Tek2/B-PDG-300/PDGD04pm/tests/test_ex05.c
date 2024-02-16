/*
** EPITECH PROJECT, 2024
** test_ex05.c
** File description:
** test_ex05.c
*/

#include "stack.h"
#include "utils.h"

#include <criterion/criterion.h>

Test(stack_get_size, empty_stack)
{
    cr_assert_eq(stack_get_size(NULL), 0);
}

Test(stack_get_size, two_nodes)
{
    stack_t *stack = NULL;

    cr_expect(stack_push(&stack, (void *)0x1));
    cr_expect(stack_push(&stack, (void *)0x2));

    cr_assert_eq(stack_get_size(stack), 2);
}


Test(stack_is_empty, empty_stack)
{
    cr_assert(stack_is_empty(NULL));
}

Test(stack_is_empty, one_node)
{
    stack_t *stack = NULL;

    cr_expect(stack_push(&stack, NULL));

    cr_assert_not(stack_is_empty(stack));
}

Test(stack_push, three_push)
{
    stack_t *stack = NULL;

    cr_assert(stack_push(&stack, (void *)0x1));
    cr_assert(stack_push(&stack, (void *)0x2));
    cr_assert(stack_push(&stack, (void *)0x3));
    cr_assert(compare_list(stack, (void *[]){(void *)0x3, (void *)0x2, (void *)0x1}, 3));
}

Test(stack_pop, three_nodes)
{
    stack_t *stack = NULL;

    cr_expect(stack_push(&stack, (void *)0x1));
    cr_expect(stack_push(&stack, (void *)0x2));
    cr_expect(stack_push(&stack, (void *)0x3));

    cr_assert(stack_pop(&stack));
    cr_assert(compare_list(stack, (void *[]){(void *)0x2, (void *)0x1}, 2));

    cr_assert(stack_pop(&stack));
    cr_assert(compare_list(stack, (void *[]){(void *)0x1}, 1));

    cr_assert(stack_pop(&stack));
    cr_assert(compare_list(stack, (void *[]){}, 0));

    cr_assert_not(stack_pop(&stack));
}


Test(stack_clear, three_nodes)
{
    stack_t *stack = NULL;

    cr_expect(stack_push(&stack, (void *)0x1));
    cr_expect(stack_push(&stack, (void *)0x2));
    cr_expect(stack_push(&stack, (void *)0x3));

    cr_expect_not_null(stack);
    stack_clear(&stack);

    cr_assert_null(stack);
}

Test(stack_clear, empty_stack)
{
    stack_t *stack = NULL;

    stack_clear(&stack);
    cr_assert_null(stack);
}

Test(stack_top, three_nodes)
{
    stack_t *stack = NULL;

    cr_expect(stack_push(&stack, (void *)0x1));
    cr_expect(stack_push(&stack, (void *)0x2));
    cr_expect(stack_push(&stack, (void *)0x3));

    cr_assert_eq(stack_top(stack), (void *)0x3);
}

Test(stack_top, empty_stack)
{
    cr_assert_eq(stack_top(NULL), NULL);
}
