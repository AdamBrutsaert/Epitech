#include "raytracer/materials/Color.hpp"

#include "raytracer/maths/Interval.hpp"

namespace rt::materials {
    static inline double LinearToGamma(double linear_component)
    {
        if (linear_component > 0)
            return sqrt(linear_component);

        return 0;
    }

    std::tuple<int, int, int> ColorToRGB(const Color& color)
    {
        auto r = color.x;
        auto g = color.y;
        auto b = color.z;

        r = LinearToGamma(r);
        g = LinearToGamma(g);
        b = LinearToGamma(b);

        static const rt::maths::Interval intensity(0.0, 0.999);
        int rbyte = int(256 * intensity.clamp(r));
        int gbyte = int(256 * intensity.clamp(g));
        int bbyte = int(256 * intensity.clamp(b));

        return {rbyte, gbyte, bbyte};
    }

    void WritePixel(std::ostream& out, const Color& color)
    {
        auto [rbyte, gbyte, bbyte] = ColorToRGB(color);

        out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    }
}
