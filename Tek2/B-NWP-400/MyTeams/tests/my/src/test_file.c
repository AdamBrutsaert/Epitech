/*
** EPITECH PROJECT, 2024
** test_vec.c
** File description:
** test_vec.c
*/

#include "my/memory/file.h"

#include <criterion/criterion.h>
#include <stdio.h>

Test(file, open)
{
    file_t *file = file_create();

    cr_assert(file_open(file, "../tests/my/assets/file1.txt", FILE_MODE_READ_ONLY));
    file_destroy(file);
}

Test(file, read)
{
    file_t *file = file_create();
    char buffer[16];

    cr_assert(file_open(file, "../tests/my/assets/file1.txt", FILE_MODE_READ_ONLY));

    auto bytes_read = file_read(file, buffer, 16);
    cr_assert_gt(bytes_read, 0);
    cr_assert_arr_eq(buffer, "hello, world!\n", bytes_read);

    file_destroy(file);
}

Test(file, write)
{
    file_t *file = file_create();
    char buffer[16];

    cr_assert(file_open(file, "../tests/my/assets/file2.txt", FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE));

    auto bytes_wrote = file_write(file, "hello, test!", 12);
    cr_assert_gt(bytes_wrote, 0);

    file_destroy(file);
    file = nullptr;

    file = file_create();
    cr_assert(file_open(file, "../tests/my/assets/file2.txt", FILE_MODE_READ_ONLY));

    auto bytes_read = file_read(file, buffer, 12);
    cr_assert_gt(bytes_read, 0);
    cr_assert_arr_eq(buffer, "hello, test!\n", bytes_read);

    file_destroy(file);
    remove("../tests/my/assets/file2.txt");
}

Test(file, read_all)
{
    file_t *file = file_create();

    cr_assert(file_open(file, "../tests/my/assets/file1.txt", FILE_MODE_READ_ONLY));

    string_t *content = file_read_all(file);
    cr_assert_str_eq(STRING_CDATA(content), "hello, world!\n");
    string_destroy(content);

    file_destroy(file);
}
