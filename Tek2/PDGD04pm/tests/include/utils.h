/*
** EPITECH PROJECT, 2024
** utils.h
** File description:
** utils.h
*/

#pragma once

#include "int_list.h"
#include "list.h"

#include <stddef.h>

bool compare_int_list(int_list_t *list, int *expected, size_t size);
bool compare_list(list_t *list, void **expected, size_t size);
