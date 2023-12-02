/*
** EPITECH PROJECT, 2022
** test_btree_apply_prefix
** File description:
** Implementation of test_btree_apply_prefix
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "tests_utils.h"

static int apply(void *item)
{
    static int counter = 1;

    *(int*)(item) += counter;
    counter++;
    return 0;
}

Test(btree, apply_prefix)
{
    btree_t *root = create_empty_tree();

    btree_apply_prefix(root, &apply);
    cr_assert_eq(*(int*)root->item, 1);
    cr_assert_eq(*(int*)root->left->item, 2);
    cr_assert_eq(*(int*)root->left->left->item, 3);
    cr_assert_eq(*(int*)root->left->right->item, 4);
    cr_assert_eq(*(int*)root->right->item, 5);
    cr_assert_eq(*(int*)root->right->left->item, 6);
    cr_assert_eq(*(int*)root->right->right->item, 7);
    free_tree(root);
}
