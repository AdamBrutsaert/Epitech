/*
** EPITECH PROJECT, 2024
** string_init.c
** File description:
** string_init.c
*/

#include "string.h"

#include <string.h>

static void string_init2(string_t *self)
{
    self->split_s = &split_s;
    self->split_c = &split_c;
    self->print = &print;
    self->join_c = &join_c;
    self->join_s = &join_s;
    self->substr = &substr;
}

void string_init(string_t *self, const char *s)
{
    self->str = s == NULL ? NULL : strdup(s);
    self->assign_s = &assign_s;
    self->assign_c = &assign_c;
    self->append_s = &append_s;
    self->append_c = &append_c;
    self->at = &at;
    self->clear = &clear;
    self->length = &length;
    self->compare_s = &compare_s;
    self->compare_c = &compare_c;
    self->copy = &copy;
    self->c_str = &c_str;
    self->empty = &empty;
    self->find_s = &find_s;
    self->find_c = &find_c;
    self->insert_c = &insert_c;
    self->insert_s = &insert_s;
    self->to_int = &to_int;
    string_init2(self);
}
