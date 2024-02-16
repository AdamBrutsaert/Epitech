/*
** EPITECH PROJECT, 2021
** ex06.c
** File description:
** ex06.c
*/

#include <stdio.h>

#include "list.h"
#include "int.h"
#include "new.h"

int main(void)
{
    Object *list = new(List, 10, Int, 0);
    Object *it = begin(list);
    Object *it_end = end(list);

    setitem(list, 5, 12);
    setitem(list, 6, 13);

    while (lt(it, it_end))
    {
        char *fdp = str(getval(it));
        printf("%s\n", fdp);
        fflush(stdout);
        free(fdp);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(list);
    return (0);
}
