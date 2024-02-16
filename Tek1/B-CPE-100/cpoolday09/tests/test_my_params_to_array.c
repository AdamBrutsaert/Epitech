/*
** EPITECH PROJECT, 2022
** test_my_params_to_array
** File description:
** Implementation of test_my_param_to_array
*/

#include <stdlib.h>
#include <criterion/criterion.h>

struct info_param *my_params_to_array(int ac, char **av);

static void free_arr(struct info_param *array)
{
    for (struct info_param *ptr = array; ptr->str; ptr++) {
        free(ptr->copy);
        for (unsigned int i = 0; ptr->word_array[i]; i++)
            free(ptr->word_array[i]);
        free(ptr->word_array);
    }
    free(array);
}

Test(my_params_to_array, one)
{
    int ac = 1;
    char *av[] = {"test.c"};
    struct info_param *params = my_params_to_array(ac, av);

    cr_assert_eq(params[0].length, 6);
    cr_assert_str_eq(params[0].str, av[0]);
    cr_assert_str_eq(params[0].copy, av[0]);
    cr_assert_str_eq(params[0].word_array[0], "test");
    cr_assert_str_eq(params[0].word_array[1], "c");
    cr_assert_eq(params[0].word_array[2], 0);
    cr_assert_eq(params[1].str, 0);
    free_arr(params);
}

Test(my_params_to_array, empty)
{
    int ac = 0;
    char *av[] = {0};
    struct info_param *params = my_params_to_array(ac, av);

    cr_assert_eq(params->str, 0);
    free_arr(params);
}

Test(my_params_to_array, many)
{
    int ac = 5;
    char *av[] = {"0", "1", "2", "3", "4"};
    struct info_param *params = my_params_to_array(ac, av);
    char str[] = "0";

    for (int i = 0; i < ac; i++) {
        cr_assert_eq(params[i].length, 1);
        cr_assert_str_eq(params[i].str, av[i]);
        cr_assert_str_eq(params[i].copy, av[i]);
        *str = '0' + i;
        cr_assert_str_eq(params[i].word_array[0], str);
        cr_assert_eq(params[i].word_array[1], 0);
    }
    free_arr(params);
}
