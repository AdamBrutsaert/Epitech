/*
** EPITECH PROJECT, 2023
** gol_check_map.c
** File description:
** gol_check_map.c
*/

#include "gameoflife.h"

int compare_line_lengh(int l, int k, int j)
{
    if (l > 0 && k != j)
        return -1;
    return 0;
}

int verify_map(char *str, int j, int k, int l)
{
    int i = 0;
    int check = 0;

    for (i = 0 ; str[i] ; i++) {
        if (str[i] != '.' && str[i] != 'X' && str[i] != '\n')
            return -1;
        if (str[i] == '\n') {
            check = compare_line_lengh(l, k, j);
            k = j;
            j = 0;
            l++;
        } else {
            j++;
        }
        if (check == -1)
            return -1;
    }
    return i;
}

bool gol_check_map(gol_t *gol)
{
    int i = 0;
    int line_lengh = 0;
    int last_line_lengh = 0;
    int lines = 0;

    if (gol->current[0] == '\0')
        return false;
    i = verify_map(gol->current, line_lengh, last_line_lengh, lines);
    if (i == -1)
        return false;
    if (gol->current[i - 1] != '\n')
        return false;
    return true;
}
