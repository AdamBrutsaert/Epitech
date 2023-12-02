/*
** EPITECH PROJECT, 2022
** test_btree_apply_infix
** File description:
** Implementation of test_btree_apply_infix
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

Test(btree, apply_infix)
{
    btree_t *root = create_empty_tree();

    btree_apply_infix(root, &apply);
    cr_assert_eq(*(int*)root->item, 4);
    cr_assert_eq(*(int*)root->left->item, 2);
    cr_assert_eq(*(int*)root->left->left->item, 1);
    cr_assert_eq(*(int*)root->left->right->item, 3);
    cr_assert_eq(*(int*)root->right->item, 6);
    cr_assert_eq(*(int*)root->right->left->item, 5);
    cr_assert_eq(*(int*)root->right->right->item, 7);
    free_tree(root);
}
