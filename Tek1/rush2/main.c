/*
** EPITECH PROJECT, 2022
** main
** File description:
** Implementation of main
*/

#include "my.h"
#include "frequencies.h"

extern void print_line(char const *str, char c);
extern void print_result(float en, float fr, float ge, float es);
extern float calculate_score(char const *str, char c, float const alphabet[26]);

int main(int argc, char **argv)
{
    float en_score = 0.0f;
    float fr_score = 0.0f;
    float ge_score = 0.0f;
    float es_score = 0.0f;
    float current_frequency;

    if (argc <= 2)
        return 84;
    my_strlowcase(argv[1]);
    for (unsigned int i = 2; i < argc; i++) {
        print_line(argv[1], argv[i][0]);
        en_score += calculate_score(argv[1], argv[i][0], en_frequencies);
        fr_score += calculate_score(argv[1], argv[i][0], fr_frequencies);
        ge_score += calculate_score(argv[1], argv[i][0], ge_frequencies);
        es_score += calculate_score(argv[1], argv[i][0], es_frequencies);
    }
    print_result(en_score, fr_score, ge_score, es_score);
    return 0;
}
