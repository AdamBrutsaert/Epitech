#pragma once

#include "raytracer/core/Ray.hpp"
#include "Interval.hpp"
#include "Vector3.hpp"

#include <cstdint>

namespace rt::maths {
    class AABB {
    public:
        Interval x, y, z;
        static const AABB Empty, Universe;

        AABB() = default;
        AABB(const Interval& x, const Interval& y, const Interval& z);
        AABB(const Point3& a, const Point3& b);
        AABB(const AABB& box0, const AABB& box1);
        ~AABB() = default;

        const Interval& axisInterval(uint8_t axis) const;
        int longestAxis() const;
        bool hit(const rt::core::Ray& ray, Interval interval) const;
    };

    inline AABB operator+(const AABB& bbox, const Vector3& offset)
    {
        return AABB(bbox.x + offset.x, bbox.y + offset.y, bbox.z + offset.z);
    }

    inline AABB operator+(const Vector3& offset, const AABB& bbox)
    {
        return offset + bbox;
    }
}
