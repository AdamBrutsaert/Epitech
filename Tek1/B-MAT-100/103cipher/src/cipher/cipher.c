/*
** EPITECH PROJECT, 2022
** cipher.c
** File description:
** cipher.c
*/

#include "cipher.h"
#include <stddef.h>

int32_t cipher(int argc, char **argv)
{
    cipher_t cipher;

    if (cipher_parse_arguments(&cipher, argc, argv) == 84) {
        matrix_destroy(cipher.message);
        matrix_destroy(cipher.key);
        return 84;
    }
    if (cipher.flag == ENCRYPT) {
        cipher_encrypt(&cipher);
    } else {
        cipher_decrypt(&cipher);
    }
    matrix_destroy(cipher.message);
    matrix_destroy(cipher.key);
    return 0;
}
