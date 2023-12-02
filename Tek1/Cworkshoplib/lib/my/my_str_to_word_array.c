/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** Implementation of my_str_to_word_array
*/

#include <stdlib.h>
#include "my.h"

static char is_alphanumerical(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    if (c >= 'a' && c <= 'z')
        return 1;
    if (c >= 'A' && c <= 'Z')
        return 1;
    return 0;
}

static unsigned int count_words(char const *str)
{
    unsigned int count = 0;
    char in_word = 0;

    for (; *str; str++) {
        if (!in_word && is_alphanumerical(*str)) {
            in_word = 1;
            count++;
        }
        if (in_word && !is_alphanumerical(*str))
            in_word = 0;
    }
    return count;
}

static char *pop_word(char const **str)
{
    unsigned int length = 0;
    char *word;

    while (!is_alphanumerical(**str))
        (*str)++;
    for (; is_alphanumerical(**str); (*str)++)
        length++;
    word = malloc(sizeof(char *) * (length + 1));
    if (word) {
        my_strncpy(word, (*str) - length, length);
        word[length] = '\0';
    }
    return word;
}

char **my_str_to_word_array(char const *str)
{
    unsigned int count = count_words(str);
    char **array = malloc(sizeof(char *) * (count + 1));

    if (array) {
        array[count] = 0;
        for (unsigned int i = 0; i < count; i++)
            array[i] = pop_word(&str);
    }
    return array;
}
