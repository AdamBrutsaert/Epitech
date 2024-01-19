/*
** EPITECH PROJECT, 2024
** string.h
** File description:
** string.h
*/

#pragma once

#include <stddef.h>

typedef struct string_s string_t;

struct string_s {
    char *str;
    void (*assign_s)(string_t *self, const string_t *str);
    void (*assign_c)(string_t *self, const char *s);
    void (*append_s)(string_t *self, const string_t *ap);
    void (*append_c)(string_t *self, const char *ap);
    char (*at)(const string_t *self, size_t pos);
    void (*clear)(string_t *self);
    int (*length)(const string_t *self);
    int (*compare_s)(const string_t *self, const string_t *str);
    int (*compare_c)(const string_t *self, const char *str);
    size_t (*copy)(const string_t *self, char *s, size_t n, size_t pos);
    const char *(*c_str)(const string_t *self);
    int (*empty)(const string_t *self);
    int (*find_s)(const string_t *self, const string_t *str, size_t pos);
    int (*find_c)(const string_t *self, const char *str, size_t pos);
    void (*insert_c)(string_t *self, size_t pos, const char *str);
    void (*insert_s)(string_t *self, size_t pos, const string_t *str);
    int (*to_int)(const string_t *self);
    string_t **(*split_s)(const string_t *self, char separator);
    char **(*split_c)(const string_t *self, char separator);
    void (*print)(const string_t *self);
    void (*join_c)(string_t *self, char delim, const char *const *array);
    void (*join_s)(string_t *self, char delim, const string_t *const *array);
    string_t *(*substr)(const string_t *self, int offset, int length);
};

void string_init(string_t *self, const char *s);
void string_destroy(string_t *self);

void assign_s(string_t *self, const string_t *str);
void assign_c(string_t *self, const char *s);

void append_s(string_t *self, const string_t *ap);
void append_c(string_t *self, const char *ap);

char at(const string_t *self, size_t pos);

void clear(string_t *self);

int length(const string_t *self);

int compare_s(const string_t *self, const string_t *str);
int compare_c(const string_t *self, const char *str);

size_t copy(const string_t *self, char *s, size_t n, size_t pos);

const char *c_str(const string_t *self);

int empty(const string_t *self);

int find_s(const string_t *self, const string_t *str, size_t pos);
int find_c(const string_t *self, const char *str, size_t pos);

void insert_c(string_t *self, size_t pos, const char *str);
void insert_s(string_t *self, size_t pos, const string_t *str);

int to_int(const string_t *self);

string_t **split_s(const string_t *self, char separator);
char **split_c(const string_t *self, char separator);

void print(const string_t *self);

void join_c(string_t *self, char delim, const char *const *array);
void join_s(string_t *self, char delim, const string_t *const *array);

string_t *substr(const string_t *self, int offset, int length);
