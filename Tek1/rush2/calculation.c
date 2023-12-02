/*
** EPITECH PROJECT, 2022
** calulcation
** File description:
** Implementation of calculation
*/

#include "my.h"

unsigned int count_occurences(char const *str, char c)
{
    unsigned int count = 0;
    int n = my_strlen(str);

    if (c >= 'A' && c <= 'Z')
        c += 32;
    for (unsigned int i = 0; i < n; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

unsigned int count_letters(char const *str)
{
    unsigned int count = 0;

    for (unsigned int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z'))
            count++;
    }
    return count;
}

float calculate_percentage(char const *str, char c)
{
    unsigned int letters = count_letters(str);
    unsigned int count = count_occurences(str, c);

    return 100.0f * (float)count / (float)letters;
}

float calculate_score(char const *str, char c, float const alphabet[26])
{
    float score;

    if (c >= 'A' && c <= 'Z')
        c += 32;
    score = calculate_percentage(str, c) - alphabet[c - 'a'];
    return score < 0 ? -score : score;
}
