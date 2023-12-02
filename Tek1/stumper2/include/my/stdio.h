/*
** EPITECH PROJECT, 2023
** stdio.h
** File description:
** stdio.h
*/

#pragma once

void my_puts(const char *string);
void my_putc(char character);

void my_eputs(const char *string);
void my_eputc(char character);

char *my_readfd(int fd);
char *my_readfile(const char *file);
