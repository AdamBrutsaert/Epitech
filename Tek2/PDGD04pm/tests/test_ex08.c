/*
** EPITECH PROJECT, 2024
** test_ex08.c
** File description:
** test_ex08.c
*/

#include "tree.h"
#include "stack.h"
#include "queue.h"

#include <criterion/criterion.h>
#include <criterion/redirect.h>

static void dump(void *data)
{
    printf("%p\n", data);
}

static bool push_stack(void *container, void *data)
{
    return stack_push((stack_t **)container, data);
}

static void *pop_stack(void *container)
{
    void *data = stack_top(*(stack_t **)container);

    stack_pop((stack_t **)container);
    return data;
}

static bool push_queue(void *container, void *data)
{
    return queue_push((queue_t **)container, data);
}

static void *pop_queue(void *container)
{
    void *data = queue_front(*(queue_t **)container);

    queue_pop((queue_t **)container);
    return data;
}

static bool create_tree(tree_t **tree)
{
    if (!init_tree(tree, (void *)0x42))
        return false;

    tree_t *node = NULL;
    node = tree_add_child(*tree, (void *)0x1);
    if (node == NULL)
        return false;
    if (tree_add_child(node, (void *)0x11) == NULL)
        return false;

    if (tree_add_child(*tree, (void *)0x2) == NULL)
        return false;

    node = tree_add_child(*tree, (void *)0x3);
    if (node == NULL)
        return false;
    if (tree_add_child(node, (void *)0x31) == NULL)
        return false;
    if (tree_add_child(node, (void *)0x32) == NULL)
        return false;
    if (tree_add_child(node, (void *)0x33) == NULL)
        return false;

    return true;
}

Test(tree_is_empty, empty_tree)
{
    cr_assert(tree_is_empty(NULL));
}

Test(tree_is_empty, non_empty)
{
    tree_t *tree = NULL;

    cr_expect(init_tree(&tree, (void *)0x1));

    cr_assert_not(tree_is_empty(tree));
}

Test(tree_node_dump, empty, .init = cr_redirect_stdout)
{
    tree_node_dump(NULL, dump);
    fflush(stdout);

    cr_assert_stdout_eq_str("");
}

Test(tree_node_dump, non_empty, .init = cr_redirect_stdout)
{
    tree_t *tree = NULL;

    cr_expect(init_tree(&tree, (void *)0x1));

    tree_node_dump(tree, dump);
    fflush(stdout);

    cr_assert_stdout_eq_str("0x1\n");
}

Test(init_tree, init)
{
    tree_t *tree = NULL;

    cr_assert(init_tree(&tree, (void *)0x1));
    cr_assert_eq(tree->children, NULL);
    cr_assert_eq(tree->data, (void *)0x1);
}

Test(tree_add_child, add_one)
{
    tree_t *tree = NULL;
    tree_t *child;

    cr_expect(init_tree(&tree, (void *)0x1));

    child = tree_add_child(tree, (void *)0x2);
    cr_assert_not_null(child);
    cr_assert_eq(child->children, NULL);
    cr_assert_eq(child->data, (void *)0x2);

    cr_assert_eq(list_get_size(tree->children), 1);
    cr_assert_eq(list_get_elem_at_position(tree->children, 0), child);
}

Test(tree_add_child, add_two)
{
    tree_t *tree = NULL;
    tree_t *child;
    tree_t *child2;

    cr_expect(init_tree(&tree, (void *)0x1));

    child = tree_add_child(tree, (void *)0x2);
    cr_assert_not_null(child);
    cr_assert_eq(child->children, NULL);
    cr_assert_eq(child->data, (void *)0x2);

    child2 = tree_add_child(tree, (void *)0x3);
    cr_assert_not_null(child);
    cr_assert_eq(child2->children, NULL);
    cr_assert_eq(child2->data, (void *)0x3);

    cr_assert_eq(list_get_size(tree->children), 2);
    cr_assert_eq(list_get_elem_at_position(tree->children, 0), child);
    cr_assert_eq(list_get_elem_at_position(tree->children, 1), child2);
}


Test(tree_destroy, empty)
{
    tree_t *tree = NULL;

    cr_assert_not(tree_destroy(&tree));
}

Test(tree_destroy, non_empty)
{
    tree_t *tree = NULL;
    tree_t *child;

    cr_expect(init_tree(&tree, (void *)0x1));

    child = tree_add_child(tree, (void *)0x2);
    cr_assert_not_null(child);

    cr_expect_not_null(tree);
    cr_assert(tree_destroy(&tree));
    cr_assert_null(tree);
}

Test(tree_traversal, empty, .init = cr_redirect_stdout)
{
    stack_t *stack = NULL;
    container_t container = {
        .container = &stack,
        .push_func = push_stack,
        .pop_func = pop_stack,
    };

    tree_traversal(NULL, &container, dump);
    fflush(stdout);

    cr_assert_stdout_eq_str("");
}

Test(tree_traversal, stack_based, .init = cr_redirect_stdout)
{
    stack_t *stack = NULL;
    container_t container = {
        .container = &stack,
        .push_func = push_stack,
        .pop_func = pop_stack,
    };
    tree_t *tree = NULL;

    cr_expect(create_tree(&tree));

    tree_traversal(tree, &container, dump);
    fflush(stdout);

    cr_assert_stdout_eq_str("0x42\n0x3\n0x33\n0x32\n0x31\n0x2\n0x1\n0x11\n");
}

Test(tree_traversal, queue_based, .init = cr_redirect_stdout)
{
    stack_t *stack = NULL;
    container_t container = {
        .container = &stack,
        .push_func = push_queue,
        .pop_func = pop_queue,
    };
    tree_t *tree = NULL;

    cr_expect(create_tree(&tree));

    tree_traversal(tree, &container, dump);
    fflush(stdout);

    cr_assert_stdout_eq_str("0x42\n0x1\n0x2\n0x3\n0x11\n0x31\n0x32\n0x33\n");
}
