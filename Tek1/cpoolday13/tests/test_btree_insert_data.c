/*
** EPITECH PROJECT, 2022
** test_btree_insert_data
** File description:
** Implementation of test_btree_insert_data
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "tests_utils.h"

static btree_t *create_sorted_tree(void)
{
    btree_t *root = create_empty_tree();

    *(int*)root->item = 50;
    *(int*)root->left->item = 25;
    *(int*)root->left->left->item = 12;
    *(int*)root->left->right->item = 30;
    *(int*)root->right->item = 75;
    *(int*)root->right->left->item = 60;
    *(int*)root->right->right->item = 85;
    return root;
}

static int compare(void *a, void *b)
{
    return *(int*)a - *(int*)b;
}

Test(btree, insert_data)
{
    btree_t *root = create_sorted_tree();
    int *item = malloc(sizeof(int));

    *item = 95;
    btree_insert_data(&root, item, compare);
    cr_assert_eq(*(int*)root->item, 50);
    cr_assert_eq(*(int*)root->left->item, 25);
    cr_assert_eq(*(int*)root->left->left->item, 12);
    cr_assert_eq(*(int*)root->left->right->item, 30);
    cr_assert_eq(*(int*)root->right->item, 75);
    cr_assert_eq(*(int*)root->right->left->item, 60);
    cr_assert_eq(*(int*)root->right->right->item, 85);
    cr_assert_eq(*(int*)root->right->right->right->item, 95);
    free_tree(root);
}

Test(btree, insert_data2)
{
    btree_t *root = create_sorted_tree();
    int *item = malloc(sizeof(int));

    *item = 0;
    btree_insert_data(&root, item, compare);
    cr_assert_eq(*(int*)root->item, 50);
    cr_assert_eq(*(int*)root->left->item, 25);
    cr_assert_eq(*(int*)root->left->left->item, 12);
    cr_assert_eq(*(int*)root->left->left->left->item, 0);
    cr_assert_eq(*(int*)root->left->right->item, 30);
    cr_assert_eq(*(int*)root->right->item, 75);
    cr_assert_eq(*(int*)root->right->left->item, 60);
    cr_assert_eq(*(int*)root->right->right->item, 85);
    free_tree(root);
}
