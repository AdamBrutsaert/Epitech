/*
** EPITECH PROJECT, 2024
** StupidUnitConverter.cpp
** File description:
** StupidUnitConverter.cpp
*/

#include <iostream>
#include <sstream>
#include <optional>
#include <iomanip>

struct ParsedLine {
    double value;
    std::string unit;
};

static std::optional<ParsedLine> parseNextLine(const std::string& input)
{
    std::istringstream iss(input);

    std::string token;
    if (!(iss >> token))
        return std::nullopt;

    std::string unit;
    if (!(iss >> unit))
        return std::nullopt;

    if (unit != "Celsius" && unit != "Fahrenheit")
        return std::nullopt;

    try {
        return {{std::stod(token), unit}};
    } catch (std::exception &e) {
        return std::nullopt;
    }
}

static void convert(ParsedLine& parsed)
{
    if (parsed.unit == "Fahrenheit") {
        parsed.unit = "Celsius";
        parsed.value = 5.0 / 9.0 * (parsed.value - 32);
    } else {
        parsed.unit = "Fahrenheit";
        parsed.value = 9.0 / 5.0 * parsed.value + 32;
    }
}

int main(void)
{
    while (true) {
        std::string input;

        if (!std::getline(std::cin, input))
            return 0;

        auto parsed = parseNextLine(input);

        if (parsed.has_value()) {
            convert(parsed.value());
            std::cout << std::fixed << std::setprecision(3)
                      << std::setw(16) << std::right << parsed.value().value
                      << std::setw(16) << std::right << parsed.value().unit << std::endl;
        } else {
            std::cerr << "Failed to parse input. Please try again." << std::endl;
        }
    }

    return 0;
}
