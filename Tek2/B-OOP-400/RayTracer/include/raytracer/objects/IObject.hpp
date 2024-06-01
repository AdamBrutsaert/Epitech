#pragma once

#include "raytracer/core/Ray.hpp"
#include "raytracer/core/Hit.hpp"
#include "raytracer/maths/Interval.hpp"
#include "raytracer/maths/AABB.hpp"

namespace rt::objects {
    class IObject {
    public:
        virtual ~IObject() = default;

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const = 0;
        virtual rt::maths::AABB boundingBox() const = 0;
    };
}
