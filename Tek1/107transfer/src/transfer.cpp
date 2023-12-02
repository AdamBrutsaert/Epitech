/*
** EPITECH PROJECT, 2023
** main.cpp
** File description:
** main.cpp
*/

#include <vector>
#include <numeric>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>

static double compute(
    double x,
    const std::vector<double>& numerators,
    const std::vector<double>& denominators
)
{
    std::size_t index;

    index = 0;
    double numerator = std::accumulate(numerators.begin(), numerators.end(), 0.0,
        [&](double sum, double coefficient) -> double {
            return sum + coefficient * std::pow(x, static_cast<double>(index++));
        }
    );

    index = 0;
    double denominator = std::accumulate(denominators.begin(), denominators.end(), 0.0,
        [&](double sum, double coefficient) -> double {
            return sum + coefficient * std::pow(x, static_cast<double>(index++));
        }
    );

    return numerator / denominator;
}

static double compute_all(
    double x,
    const std::vector<std::vector<double>>& numerators,
    const std::vector<std::vector<double>>& denominators
)
{
    double product = compute(x, numerators[0], denominators[0]);

    for (size_t i = 1; i < numerators.size(); i++)
        product *= compute(x, numerators[i], denominators[i]);

    return product;
}

static void transfer(
    const std::vector<std::vector<double>>& numerators,
    const std::vector<std::vector<double>>& denominators
)
{
    double x = 0.0;
    std::cout << std::fixed;

    for (size_t i = 0; i <= 1000; i++) {
        std::cout << std::setprecision(3) << x;
        std::cout << " -> ";
        std::cout << std::setprecision(5) << compute_all(x, numerators, denominators);
        std::cout << "\n";
        x += 0.001;
    }
}

static bool parse_string(const char *string, std::vector<double>& coefficients)
{
    const char *begin = string;
    char *end = nullptr;

    for (size_t i = 0; !end || *end != '\0'; i++) {
        if (*begin < '0' || *begin > '9')
            return false;

        coefficients.push_back(static_cast<double>(std::strtoll(begin, &end, 10)));

        if (*end != '*' && *end != '\0')
            return false;

        begin = end + 1;
    }

    return true;
}

static bool parse(
    int argc,
    char **argv,
    std::vector<std::vector<double>>& numerators,
    std::vector<std::vector<double>>& denominators)
{
    if (argc < 3 || argc % 2 == 0)
        return false;

    for (size_t i = 0; i * 2 + 1 < argc; i++) {
        numerators.emplace_back();
        denominators.emplace_back();

        if (!parse_string(argv[i * 2 + 1], numerators[i]))
            return false;
        if (!parse_string(argv[i * 2 + 2], denominators[i]))
            return false;

        // Check if denominator is not 0
        bool hasOnlyZero = true;

        for (size_t j = 0; j < denominators[i].size(); j++) {
            if (denominators[i][j] != 0.0) {
                hasOnlyZero = false;
                break;
            }
        }

        if (hasOnlyZero)
            return false;
    }

    return true;
}

int main(int argc, char **argv)
{
    std::vector<std::vector<double>> numerators;
    std::vector<std::vector<double>> denominators;

    if (!parse(argc, argv, numerators, denominators))
        return 84;

    transfer(numerators, denominators);

    return 0;
}
