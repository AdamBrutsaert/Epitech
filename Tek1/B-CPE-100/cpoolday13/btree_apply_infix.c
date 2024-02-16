/*
** EPITECH PROJECT, 2022
** btree_apply_infix
** File description:
** Implementation of btree_apply_infix
*/

#include "btree.h"

void btree_apply_infix(btree_t *root, int (*applyf)(void *))
{
    if (root == 0)
        return;
    btree_apply_infix(root->left, applyf);
    (*applyf)(root->item);
    btree_apply_infix(root->right, applyf);
}
