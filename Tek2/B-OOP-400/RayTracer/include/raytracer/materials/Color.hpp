#pragma once

#include "raytracer/maths/Vector3.hpp"

#include <iostream>

namespace rt::materials {
    using Color = rt::maths::Vector3;

    std::tuple<int, int, int> ColorToRGB(const Color& color);
    void WritePixel(std::ostream& out, const Color& color);
}
