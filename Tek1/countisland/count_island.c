/*
** EPITECH PROJECT, 2022
** count_island
** File description:
** Implementation of count_island
*/

#include <stdio.h>

int propagate(char **world, unsigned int row, unsigned int column, int n)
{
    if (world[row][column] == 'X') {
        world[row][column] = '0' + n;
        if (row != 0)
            propagate(world, row - 1, column, n);
        if (world[row + 1] != 0)
            propagate(world, row + 1, column, n);
        if (column != 0)
            propagate(world, row, column - 1, n);
        if (world[row][column + 1] != 0)
            propagate(world, row, column + 1, n);
        return 1;
    }
    return 0;
}

int count_island(char **world)
{
    int count = 0;

    for (unsigned int row = 0; world[row]; row++) {
        for (unsigned int column = 0; world[row][column]; column++)
            count += propagate(world, row, column, count);
    }
    return count;
}
