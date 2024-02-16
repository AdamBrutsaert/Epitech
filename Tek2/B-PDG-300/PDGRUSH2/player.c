/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercice 01
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "player.h"

typedef struct {
    Class base;
    char *identifier;
    int power;
} PlayerClass;

static void Player_ctor(PlayerClass *this, va_list *args)
{
    (void)args;
    this->identifier = strdup("Kreog");
    this->power = rand() % 42;
    printf("Player()\n");
}

static void Player_dtor(PlayerClass *this)
{
    free(this->identifier);
    printf("~Player()\n");
}

static char *Player_to_string(PlayerClass *this)
{
    char *str = calloc(100, sizeof(char));

    if (!str)
        raise("Out of memory");
    sprintf(str, "<Player>");
    return str;
}

static const PlayerClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(PlayerClass),
        .__name__ = "Player",
        .__ctor__ = (ctor_t)&Player_ctor,
        .__dtor__ = (dtor_t)&Player_dtor,
        .__str__ = (to_string_t)&Player_to_string,
        .__add__ = NULL,
        .__sub__ = NULL,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .identifier = NULL,
    .power = -1
};

const Class *Player = (const Class *)&_description;
