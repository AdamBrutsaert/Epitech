/*
** EPITECH PROJECT, 2022
** btree_create_node
** File description:
** Implementation of btree_create_node
*/

#include "btree.h"
#include <stdlib.h>

btree_t *btree_create_node(void *item)
{
    btree_t *node = malloc(sizeof(btree_t));

    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
}
