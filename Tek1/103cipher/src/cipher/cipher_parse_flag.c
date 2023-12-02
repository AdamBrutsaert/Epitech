/*
** EPITECH PROJECT, 2022
** cipher_parse_flag.c
** File description:
** cipher_parse_flag.c
*/

#include "cipher.h"
#include <string.h>

int32_t cipher_parse_flag(cipher_t *cipher, char const *flag)
{
    if (!strcmp(flag, "0")) {
        cipher->flag = ENCRYPT;
    } else if (!strcmp(flag, "1")) {
        cipher->flag = DECRYPT;
    } else {
        return 84;
    }
    return 0;
}
