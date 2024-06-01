#pragma once

#include "raytracer/maths/Utils.hpp"

namespace rt::maths {
    class Interval {
    public:
        double min, max;

        Interval()
            : min(+infinity), max(-infinity)
        {
        }

        Interval(double min, double max)
            : min(min), max(max)
        {
        }

        Interval(const Interval& a, const Interval& b)
            : min(std::fmin(a.min, b.min)), max(std::fmax(a.max, b.max))
        {
        }

        inline double size() const
        {
            return max - min;
        }

        inline bool contains(double x) const
        {
            return min <= x && x <= max;
        }

        inline bool surrounds(double x) const
        {
            return min < x && x < max;
        }

        inline double clamp(double x) const
        {
            if (x < min) return min;
            if (x > max) return max;
            return x;
        }

        inline Interval expand(double delta) const {
            auto padding = delta * 0.5;
            return Interval(min - padding, max + padding);
        }

        static const Interval Empty;
        static const Interval Universe;
    };

    inline Interval operator+(const Interval& a, double displacement)
    {
        return Interval(a.min + displacement, a.max + displacement);
    }

    inline Interval operator+(double displacement, const Interval& a)
    {
        return a + displacement;
    }
}
