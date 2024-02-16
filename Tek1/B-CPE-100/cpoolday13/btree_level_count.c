/*
** EPITECH PROJECT, 2022
** btree_level_count
** File description:
** Implementation of btree_level_count
*/

#include "btree.h"

static int max(int a, int b)
{
    return a > b ? a : b;
}

size_t btree_level_count(btree_t const *root)
{
    if (root == 0)
        return 0;
    return 1
        + max(btree_level_count(root->left), btree_level_count(root->right));
}
