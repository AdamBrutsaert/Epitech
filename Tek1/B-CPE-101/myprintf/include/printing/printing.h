/*
** EPITECH PROJECT, 2022
** printing
** File description:
** Header of printing
*/

#pragma once

#include "format.h"

// Utils
int print_before(format_t *format, int width, int length);
int print_after(format_t *format, int width, int length);
int print_unsigned_before(format_t *format, int width, int length, char *pre);
int print_float_before(format_t *format, int width, int length);

// Numbers
int print_di(format_t *format);
int print_u(format_t *format);
int print_f(format_t *format);
int print_f_maj(format_t *format);
int print_e(format_t *format);
int print_e_maj(format_t *format);
int print_g(format_t *format);
int print_g_maj(format_t *format);
int print_b(format_t *format);
int print_o(format_t *format);
int print_x(format_t *format);
int print_x_maj(format_t *format);
int print_a(format_t *format);
int print_a_maj(format_t *format);

// Text
int print_c(format_t *format);
int print_lc(format_t *format);
int print_s(format_t *format);
int print_ls(format_t *format);
int print_s_maj(format_t *format);
int print_ls_maj(format_t *format);

// Other
int print_n(format_t *format);
int print_p(format_t *format);
int print_percentage(format_t *format);
int print_error(format_t *format);

static int (*const TOKENS_TO_FUNC[10][22])(format_t *) = {
    // hh
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_c, &print_s, &print_p, &print_n,
        &print_percentage, &print_b, &print_s_maj, &print_error},
    // ll
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // q
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // h
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_c, &print_s, &print_p, &print_n,
        &print_percentage, &print_b, &print_s_maj, &print_error},
    // l
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // L
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // j
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // z
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // t
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_lc, &print_ls, &print_p, &print_n,
        &print_percentage, &print_b, &print_ls_maj, &print_error},
    // None
    {&print_di, &print_di, &print_o, &print_u, &print_x, &print_x_maj,
        &print_e, &print_e_maj, &print_f, &print_f_maj, &print_g, &print_g_maj,
        &print_a, &print_a_maj, &print_c, &print_s, &print_p, &print_n,
        &print_percentage, &print_b, &print_s_maj, &print_error},
};
