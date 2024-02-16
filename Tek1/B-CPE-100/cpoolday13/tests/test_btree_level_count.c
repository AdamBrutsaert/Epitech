/*
** EPITECH PROJECT, 2022
** test_btree_level_count
** File description:
** Implementation of test_btree_level_count
*/

#include <criterion/criterion.h>
#include "btree.h"
#include "tests_utils.h"

static btree_t *create_tree(void)
{
    btree_t *root = create_empty_node();

    root->left = create_empty_node();
    root->left->left = create_empty_node();
    root->right = create_empty_node();
    root->right->left = create_empty_node();
    root->right->left->right = create_empty_node();
    return root;
}

Test(btree, level_count_0)
{
    cr_assert_eq(btree_level_count(0), 0);
}

Test(btree, level_count_1)
{
    btree_t *root = create_empty_node();

    cr_assert_eq(btree_level_count(root), 1);
    free_tree(root);
}

Test(btree, level_count_3)
{
    btree_t *root = create_empty_tree();

    cr_assert_eq(btree_level_count(root), 3);
    free_tree(root);
}

Test(btree, level_count_4)
{
    btree_t *root = create_tree();

    cr_assert_eq(btree_level_count(root), 4);
    free_tree(root);
}
