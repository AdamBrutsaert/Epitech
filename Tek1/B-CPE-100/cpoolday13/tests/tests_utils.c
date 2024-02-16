/*
** EPITECH PROJECT, 2022
** tests_utils
** File description:
** Implementation of tests_utils
*/

#include "tests_utils.h"
#include <stdio.h>
#include <stdlib.h>

void free_tree(btree_t *root)
{
    if (root == 0)
        return;
    free_tree(root->left);
    free_tree(root->right);
    free(root->item);
    free(root);
}

btree_t *create_empty_node(void)
{
    int *item = malloc(sizeof(int));
    btree_t *node;

    *item = 0;
    node = btree_create_node(item);
    return node;
}

btree_t *create_empty_tree(void)
{
    btree_t *root = create_empty_node();

    root->left = create_empty_node();
    root->right = create_empty_node();
    root->left->left = create_empty_node();
    root->left->right = create_empty_node();
    root->right->left = create_empty_node();
    root->right->right = create_empty_node();
    return root;
}

void print_tree(btree_t *root, int level)
{
    if (!root)
        return;
    for (int i = 0; i < level; i++)
        printf("\t");
    printf("Node: %d\n", *(int*)root->item);
    print_tree(root->left, level + 1);
    print_tree(root->right, level + 1);
}
