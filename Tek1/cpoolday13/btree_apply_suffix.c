/*
** EPITECH PROJECT, 2022
** btree_apply_sufffix
** File description:
** Implementation of btree_apply_suffix
*/

#include "btree.h"

void btree_apply_suffix(btree_t *root, int (*applyf)(void *))
{
    if (root == 0)
        return;
    btree_apply_suffix(root->left, applyf);
    btree_apply_suffix(root->right, applyf);
    (*applyf)(root->item);
}
