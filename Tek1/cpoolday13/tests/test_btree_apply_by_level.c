/*
** EPITECH PROJECT, 2022
** test_btree_apply_by_level
** File description:
** Implementation of btree_apply_by_level
*/

#include <criterion/criterion.h>
#include <string.h>
#include "btree.h"
#include "tests_utils.h"

static char *my_strdup(char const *str)
{
    char *s = calloc(sizeof(char), strlen(str) + 1);
    strcpy(s, str);
    return s;
}

static void apply2(void *item, int level, int is_first_elem)
{
    if (!strcmp((char*)item, "great")) {
        cr_assert_eq(level, 3);
        cr_assert_eq(is_first_elem, 1);
    }
    if (!strcmp((char*)item, "day")) {
        cr_assert_eq(level, 3);
        cr_assert_eq(is_first_elem, 0);
    }
    if (!strcmp((char*)item, "of")) {
        cr_assert_eq(level, 3);
        cr_assert_eq(is_first_elem, 0);
    }
    if (!strcmp((char*)item, "C")) {
        cr_assert_eq(level, 4);
        cr_assert_eq(is_first_elem, 1);
    }
    if (!strcmp((char*)item, "pool")) {
        cr_assert_eq(level, 4);
        cr_assert_eq(is_first_elem, 0);
    }
}

static void apply(void *item, int level, int is_first_elem)
{
    if (!strcmp((char*)item, "Good")) {
        cr_assert_eq(level, 0);
        cr_assert_eq(is_first_elem, 1);
    }
    if (!strcmp((char*)item, "Luck")) {
        cr_assert_eq(level, 1);
        cr_assert_eq(is_first_elem, 1);
    }
    if (!strcmp((char*)item, "for")) {
        cr_assert_eq(level, 2);
        cr_assert_eq(is_first_elem, 1);
    }
    if (!strcmp((char*)item, "this")) {
        cr_assert_eq(level, 2);
        cr_assert_eq(is_first_elem, 0);
    }
    apply2(item, level, is_first_elem);
}

static btree_t *create_tree(void)
{
    btree_t *root = btree_create_node(my_strdup("Good"));

    root->left = btree_create_node(my_strdup("Luck"));
    root->left->left = btree_create_node(my_strdup("for"));
    root->left->left->left = btree_create_node(my_strdup("great"));
    root->left->left->right = btree_create_node(my_strdup("day"));
    root->left->right = btree_create_node(my_strdup("this"));
    root->left->right->left = btree_create_node(my_strdup("of"));
    root->left->right->left->left = btree_create_node(my_strdup("C"));
    root->left->right->left->right = btree_create_node(my_strdup("pool"));
    return root;
}

Test(btree, apply_by_level)
{
    btree_t *root = create_tree();

    btree_apply_by_level(root, &apply);
    free_tree(root);
}
