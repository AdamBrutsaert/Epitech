/*
** EPITECH PROJECT, 2024
** z.c
** File description:
** z.c
*/

#include <unistd.h>

void zorglub(void)
{
    write(STDOUT_FILENO, "z\n", 2);
}

int main(void)
{
    zorglub();
    return 0;
}
