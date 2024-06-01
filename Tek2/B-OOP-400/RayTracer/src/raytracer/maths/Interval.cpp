#include "raytracer/maths/Interval.hpp"

namespace rt::maths {
    const Interval Interval::Empty = Interval(+infinity, -infinity);
    const Interval Interval::Universe = Interval(-infinity, +infinity);
}
