/*
** EPITECH PROJECT, 2022
** pushswap_print_operations.c
** File description:
** pushswap_print_operations.c
*/

#include "pushswap/pushswap.h"
#include "pushswap/operations.h"
#include "my/string.h"
#include "my/stdio.h"
#include <unistd.h>

static void append(char *buffer, u64_t *length, operation_t operation,
    bool_t last)
{
    static char const *operations_name[] = {
        "sa", "sb", "sc", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
    };

    my_strcpy(&buffer[*length], operations_name[operation]);
    *length += my_strlen(operations_name[operation]) + 1;
    buffer[*length - 1] = ' ' - 22 * last;
}

static void flush(char *buffer, u64_t *length)
{
    write(STDOUT_FILENO, buffer, *length);
    *length = 0;
}

void pushswap_print_operations(pushswap_t *ps)
{
    char buffer[8192];
    u64_t length = 0;

    if (ps->operations.length == 0) {
        my_printc('\n');
        return;
    }
    for (u64_t i = 0; i < ps->operations.length; i++) {
        append(buffer, &length, ((u8_t *)ps->operations.values)[i],
            i == ps->operations.length - 1);
        if (length >= 8188)
            flush(buffer, &length);
    }
    flush(buffer, &length);
}
