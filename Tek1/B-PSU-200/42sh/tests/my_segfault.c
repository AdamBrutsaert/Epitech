/*
** EPITECH PROJECT, 2023
** Minishell2
** File description:
** Test file to check if the segfault is detected
*/

#include <stdio.h>

int main(void)
{
    int i[2] = {0, 0};
    printf("%d", i[4] = 3);
}
