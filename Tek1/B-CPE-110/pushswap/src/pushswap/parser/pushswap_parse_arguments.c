/*
** EPITECH PROJECT, 2022
** pushswap_parse_arguments.c
** File description:
** pushswap_parse_arguments.c
*/

#include "pushswap/pushswap_parser.h"
#include "my/conversion.h"

status_t pushswap_parse_arguments(pushswap_parser_t *parser, int argc,
    char **argv)
{
    number_t number;
    number_t *ptr;

    for (u32_t i = 1; i < (u32_t)argc; i++) {
        number.index = i - 1;
        if (strict_str_to_i32(argv[i], &number.value) == STATUS_ERROR)
            return STATUS_ERROR;
        vector_push(&parser->numbers, &number);
        ptr = (number_t *)parser->numbers.values + number.index;
        vector_push(&parser->sorted, &ptr);
    }
    return STATUS_SUCCESS;
}
