/*
** EPITECH PROJECT, 2022
** cipher_parse_arguments.c
** File description:
** cipher_parse_arguments.c
*/

#include "cipher.h"
#include <string.h>

int32_t cipher_parse_arguments(cipher_t *cipher, int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-h"))
        return cipher_help(argv[0]);
    if (argc != 4)
        return 84;
    if (cipher_parse_flag(cipher, argv[3]) == 84)
        return 84;
    if (cipher_parse_key(cipher, argv[2]) == 84)
        return 84;
    if (cipher->flag == ENCRYPT) {
        cipher_parse_message(cipher, argv[1]);
    } else if (cipher_parse_encrypted_message(cipher, argv[1]) == 84) {
        return 84;
    }
    return 0;
}
