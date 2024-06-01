#pragma once

#include <cmath>

namespace rt::maths {
    constexpr double infinity = std::numeric_limits<double>::infinity();

    double DegreesToRadians(double degrees);

    double RandomDouble();
    double RandomDouble(double min, double max);
    int RandomInt(int min, int max);
}
