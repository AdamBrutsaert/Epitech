#include "raytracer/maths/Utils.hpp"

#include <random>

namespace rt::maths {
    double DegreesToRadians(double degrees)
    {
        return degrees * M_PI / 180.0;
    }

    double RandomDouble()
    {
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        std::mt19937 generator(std::random_device{}());

        return distribution(generator);
    }

    double RandomDouble(double min, double max)
    {
        return min + (max-min) * RandomDouble();
    }

    int RandomInt(int min, int max)
    {
        return int(RandomDouble(min, max + 1));
    }
}
