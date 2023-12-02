/*
** EPITECH PROJECT, 2022
** interface
** File description:
** Implementation of interface
*/

#include "my.h"
#include "frequencies.h"

extern void print_result(float en, float fr, float ge, float es);
extern unsigned int count_occurences(char const *str, char c);
extern float calculate_score(char const *str, char c, float const alphabet[26]);
extern void print_float(float a);

static void print_occurencies(char const *str, char c)
{
    my_putstr("The letter '");
    my_putchar(c);
    my_putstr("' appeared ");
    my_put_nbr(count_occurences(str, c));
    my_putstr(" times\n");
}

static void print_scores(float en, float fr, float ge, float es)
{
    my_putstr("------------- DIFFERENCES ------------\n");
    my_putstr("English is different by ");
    print_float(en);
    my_putstr(" points\nFrench is different by ");
    print_float(fr);
    my_putstr(" points\nGerman is different by ");
    print_float(ge);
    my_putstr(" points\nSpanish is different by ");
    print_float(es);
    my_putstr(" points\n");
    my_putstr("--------------------------------------\n\n");
}

int main(int argc, char **argv)
{
    float scores[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    float current_frequency;

    if (argc <= 2)
        return 0;
    my_strlowcase(argv[1]);
    my_putstr("--------------- REPORT ---------------\n");
    for (unsigned int i = 2; i < argc; i++) {
        print_occurencies(argv[1], argv[i][0]);
        scores[0] += calculate_score(argv[1], argv[i][0], en_frequencies);
        scores[1] += calculate_score(argv[1], argv[i][0], fr_frequencies);
        scores[2] += calculate_score(argv[1], argv[i][0], ge_frequencies);
        scores[3] += calculate_score(argv[1], argv[i][0], es_frequencies);
    }
    my_putstr("--------------------------------------\n\n");
    print_scores(scores[0], scores[1], scores[2], scores[3]);
    my_putstr(
        "Our super-intelligent algorithm detected that this language is...\n");
    print_result(scores[0], scores[1], scores[2], scores[3]);
    return 0;
}
