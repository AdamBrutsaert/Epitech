/*
** EPITECH PROJECT, 2024
** test_ex07.c
** File description:
** test_ex07.c
*/

#include "map.h"

#include <criterion/criterion.h>

static int key_comparator(const void *a, const void *b)
{
    return a - b;
}

Test(map_get_size, empty_queue)
{
    cr_assert_eq(map_get_size(NULL), 0);
}

Test(map_get_size, two_nodes)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x2, (void *)0x200, key_comparator));

    cr_assert_eq(map_get_size(map), 2);
}

Test(map_is_empty, empty_map)
{
    cr_assert(map_is_empty(NULL));
}

Test(map_is_empty, two_nodes)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x2, (void *)0x200, key_comparator));

    cr_assert_not(map_is_empty(map));
}

Test(map_add_elem__map_get_elem, two_nodes)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x2, (void *)0x200, key_comparator));

    cr_assert_eq(map_get_elem(map, (void *)0x1, key_comparator), (void *)0x100);
    cr_assert_eq(map_get_elem(map, (void *)0x2, key_comparator), (void *)0x200);
}

Test(map_add_elem, replace_value)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_assert_eq(map_get_elem(map, (void *)0x1, key_comparator), (void *)0x100);

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x200, key_comparator));
    cr_assert_eq(map_get_elem(map, (void *)0x1, key_comparator), (void *)0x200);
}

Test(map_get_elem, invalid_key)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_assert_eq(map_get_elem(map, (void *)0x2, key_comparator), NULL);
}

Test(map_del_elem, existing_key)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x2, (void *)0x200, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x3, (void *)0x300, key_comparator));
    cr_expect_eq(map_get_elem(map, (void *)0x2, key_comparator), (void *)0x200);

    cr_assert(map_del_elem(&map, (void *)0x2, key_comparator));
    cr_assert_eq(map_get_elem(map, (void *)0x2, key_comparator), NULL);
}

Test(map_del_elem, invalid_key)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect_eq(map_get_elem(map, (void *)0x1, key_comparator), (void *)0x100);

    cr_assert_not(map_del_elem(&map, (void *)0x2, key_comparator));
    cr_assert_eq(map_get_elem(map, (void *)0x1, key_comparator), (void *)0x100);
}

Test(map_clear, two_keys)
{
    map_t *map = NULL;

    cr_expect(map_add_elem(&map, (void *)0x1, (void *)0x100, key_comparator));
    cr_expect(map_add_elem(&map, (void *)0x2, (void *)0x200, key_comparator));
    cr_expect_eq(map_get_size(map), 2);

    map_clear(&map);
    cr_assert_null(map);
}

Test(map_clear, empty_list)
{
    map_t *map = NULL;

    map_clear(&map);
    cr_assert_null(map);
}
