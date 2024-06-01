#include "raytracer/maths/AABB.hpp"

namespace rt::maths {
    AABB::AABB(const Interval& x, const Interval& y, const Interval& z)
        : x(x), y(y), z(z)
    {
    }

    AABB::AABB(const Point3& a, const Point3& b)
    {
        x = (a.x < b.x) ? Interval(a.x, b.x) : Interval(b.x, a.x);
        y = (a.y < b.y) ? Interval(a.y, b.y) : Interval(b.y, a.y);
        z = (a.z < b.z) ? Interval(a.z, b.z) : Interval(b.z, a.z);
    }

    AABB::AABB(const AABB& box0, const AABB& box1)
        : x(Interval(box0.x, box1.x)), y(Interval(box0.y, box1.y)), z(Interval(box0.z, box1.z))
    {
    }

    const Interval& AABB::axisInterval(uint8_t axis) const
    {
        switch (axis) {
            case 1: return y;
            case 2: return z;
            default: return x;
        }
    }

    int AABB::longestAxis() const
    {
        if (x.size() > y.size())
            return x.size() > z.size() ? 0 : 2;
        return y.size() > z.size() ? 1 : 2;
    }

    bool AABB::hit(const rt::core::Ray& ray, Interval interval) const
    {
        const Point3& origin = ray.origin;
        const Vector3& direction = ray.direction;

        for (uint8_t axis = 0; axis < 3; axis++) {
            const Interval& axisInterval = this->axisInterval(axis);
            const double adinv = 1.0 / direction[axis];

            auto t0 = (axisInterval.min - origin[axis]) * adinv;
            auto t1 = (axisInterval.max - origin[axis]) * adinv;

            if (t0 < t1) {
                if (t0 > interval.min) interval.min = t0;
                if (t1 < interval.max) interval.max = t1;
            } else {
                if (t1 > interval.min) interval.min = t1;
                if (t0 < interval.max) interval.max = t0;
            }

            if (interval.max <= interval.min)
                return false;
        }
        return true;
    }

    const AABB AABB::Empty = AABB(Interval::Empty, Interval::Empty, Interval::Empty);
    const AABB AABB::Universe = AABB(Interval::Universe, Interval::Universe, Interval::Universe);
}
