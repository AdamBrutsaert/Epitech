/*
** EPITECH PROJECT, 2022
** btree_search_item
** File description:
** Implementation of btree_search_item
*/

#include <criterion/criterion.h>
#include "btree.h"
#include "tests_utils.h"

static btree_t *create_tree(void)
{
    btree_t *root = create_empty_tree();

    *(int*)root->item = 50;
    *(int*)root->left->item = 26;
    *(int*)root->left->left->item = 24;
    *(int*)root->left->right->item = 30;
    *(int*)root->right->item = 30;
    *(int*)root->right->left->item = 30;
    *(int*)root->right->right->item = 85;
    return root;
}

static int compare(void *a, void *b)
{
    return *(int*)a - *(int*)b != 1 && *(int*)a - *(int*)b != -1;
}

Test(btree, search_item)
{
    btree_t *root = create_tree();
    int ref = 25;
    int *value = btree_search_item(root, &ref, compare);

    cr_assert_neq(value, 0);
    cr_assert_eq(*value, 24);
    free_tree(root);
}
