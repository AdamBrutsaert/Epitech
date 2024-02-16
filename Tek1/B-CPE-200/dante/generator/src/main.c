/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "kruskal.h"
#include "naive.h"

#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    srand(time(NULL));
    if (argc == 3)
        return naive_from_args(argc, argv);
    return kruskal_from_args(argc, argv);
}
