/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 05
*/

#pragma once

#include "object.h"
#include "raise.h"

typedef struct Iterator_s Iterator;

typedef void (*incr_t)(Iterator *self);
typedef Object *(*getval_t)(Iterator *self);
typedef void (*setval_t)(Iterator *self, ...);

struct Iterator_s
{
    Class base;
    incr_t __incr__;
    getval_t __getval__;
    setval_t __setval__;
};

#define incr(it) ((Iterator *)it)->__incr__(it)
#define getval(it) ((Iterator *)it)->__getval__(it)
#define setval(it, ...) ((Iterator *)it)->__setval__(it, __VA_ARGS__)
