/*
** EPITECH PROJECT, 2023
** project.h
** File description:
** project.h
*/


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef MY_HEAD_
    #define MY_HEAD_

    void my_putstr(char *str);
    void my_puterr(char *str);
    char *open_file(char const *src);

#endif /*  MY_HEAD_  */
