/*
** EPITECH PROJECT, 2022
** btree_insert_data
** File description:
** Implementation of btree_insert_data
*/

#include "btree.h"

void btree_insert_data(btree_t **root, void *item, int(*cmpf)())
{
    if (!(*root)) {
        *root = btree_create_node(item);
    } else if ((*cmpf)(item, (*root)->item) < 0) {
        btree_insert_data(&((*root)->left), item, cmpf);
    } else {
        btree_insert_data(&((*root)->right), item, cmpf);
    }
}
