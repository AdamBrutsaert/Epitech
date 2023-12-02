/*
** EPITECH PROJECT, 2022
** my_printf.c
** File description:
** Implementation of my_printf
*/

#include "my.h"
#include "parsing/parsing.h"
#include "printing/printing.h"

// TODO check that value, width & precision index are != 0 else print them
// as errors
static int dispatch(
    format_resolution_t *res, variant_array_t *vars_array, int length)
{
    format_t format = {length, res->flags,
        vars_array->vars[res->width.index].value.as_int_max,
        vars_array->vars[res->precision.index].value.as_int_max,
        &vars_array->vars[res->value.index].value};

    return (*TOKENS_TO_FUNC[res->length_modifier][res->conversion])(&format);
}

static int process_string(char const *format,
    format_resolution_array_t *formats_array, variant_array_t *vars_array)
{
    int length = 0;

    for (int i = 0; *format; format++) {
        if (*format == '%') {
            format += formats_array->formats[i].length;
            length += dispatch(&formats_array->formats[i], vars_array, length);
            i++;
            continue;
        }
        my_putchar(*format);
        length++;
    }
    return length;
}

int my_printf(char const *format, ...)
{
    int length;
    context_t ctx;

    context_create(&ctx, format);
    va_start(ctx.ap, format);
    parse_string(&ctx);
    va_end(ctx.ap);
    length = process_string(format, ctx.formats_array, ctx.vars_array);
    context_destroy(&ctx);
    return length;
}
