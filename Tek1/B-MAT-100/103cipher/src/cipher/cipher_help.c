/*
** EPITECH PROJECT, 2022
** cipher_help.c
** File description:
** cipher_help.c
*/

#include "cipher.h"
#include <stdio.h>

int32_t cipher_help(char *program)
{
    printf("USAGE\n");
    printf("    %s message key flag\n\n", program);
    printf("DESCRIPTION\n");
    printf("    message     a message, made of ASCII characters\n");
    printf("    key         the encryption key, made of ASCII characters\n");
    printf("    flag        0 for the message to be encrypted, 1 to be decry");
    printf("pted\n");
    return 0;
}
