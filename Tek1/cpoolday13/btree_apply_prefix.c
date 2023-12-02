/*
** EPITECH PROJECT, 2022
** btree_apply_prefix
** File description:
** Implementation of btree_apply_prefix
*/

#include "btree.h"

void btree_apply_prefix(btree_t *root, int (*applyf)(void *))
{
    if (root == 0)
        return;
    (*applyf)(root->item);
    btree_apply_prefix(root->left, applyf);
    btree_apply_prefix(root->right, applyf);
}
