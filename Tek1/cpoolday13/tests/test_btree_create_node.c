/*
** EPITECH PROJECT, 2022
** test_btree_create_node
** File description:
** Implementation of test_btree_create_node.c
*/

#include <criterion/criterion.h>
#include "btree.h"
#include "tests_utils.h"

Test(btree, create_node)
{
    int *nb = malloc(sizeof(int));
    btree_t *node;

    *nb = 5;
    node = btree_create_node(nb);
    cr_assert_eq(*(int*)(node->item), 5);
    cr_assert_eq(node->item, nb);
    cr_assert_eq(node->left, 0);
    cr_assert_eq(node->right, 0);
    free_tree(node);
}
