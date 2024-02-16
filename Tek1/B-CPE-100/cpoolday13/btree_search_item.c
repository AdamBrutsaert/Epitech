/*
** EPITECH PROJECT, 2022
** btree_search_item
** File description:
** Implementation of btree_search_item
*/

#include "btree.h"

void *btree_search_item(btree_t *root, void const *data_ref, int (*cmpf)())
{
    void *item = 0;

    if (root == 0)
        return 0;
    item = btree_search_item(root->left, data_ref, cmpf);
    if (item)
        return item;
    if ((*cmpf)(root->item, data_ref) == 0)
        return root->item;
    item = btree_search_item(root->right, data_ref, cmpf);
    return item;
}
