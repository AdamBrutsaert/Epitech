/*
** EPITECH PROJECT, 2022
** test_my_show_param_array
** File description:
** Implementation of test_my_show_param_array
*/

#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

struct info_param *my_params_to_array(int ac, char **av);
int my_show_param_array(struct info_param const *par);

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

static char is_empty(FILE *out)
{
    return fgetc(out) == EOF;
}

Test(my_show_param_array, print, .init = cr_redirect_stdout)
{
    int ac = 1;
    char *av[] = {"test.c"};
    struct info_param *params = my_params_to_array(ac, av);

    my_show_param_array(params);
    cr_assert_stdout_eq_str("test.c\n6\ntest\nc\n");
    free_arr(params);
}

Test(my_show_param_array, empty, .init = cr_redirect_stdout)
{
    int ac = 0;
    char *av[] = {0};
    struct info_param *params = my_params_to_array(ac, av);

    my_show_param_array(params);
    cr_assert(is_empty(cr_get_redirected_stdout()));
    free_arr(params);
}

Test(my_show_param_array, many, .init = cr_redirect_stdout)
{
    int ac = 2;
    char *av[] = {"test.c", "-[t Hello~how are++--you?"};
    struct info_param *params = my_params_to_array(ac, av);

    my_show_param_array(params);
    cr_assert_stdout_eq_str("test.c\n6\ntest\nc\n"
                            "-[t Hello~how are++--you?"
                            "\n25\nt\nHello\nhow\nare\nyou\n");
    free_arr(params);
}
