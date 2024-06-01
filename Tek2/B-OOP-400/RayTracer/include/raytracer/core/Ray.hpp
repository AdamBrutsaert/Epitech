#pragma once

#include "raytracer/maths/Vector3.hpp"

namespace rt::core {
    class Ray {
    public:
        rt::maths::Point3 origin;
        rt::maths::Vector3 direction;

    public:
        Ray()
        {
        }

        Ray(const rt::maths::Point3& origin, const rt::maths::Vector3& direction)
            : origin(origin), direction(direction)
        {
        }

        Ray(const Ray& other) = default;

        Ray(Ray&& other) = default;

        ~Ray() = default;

        Ray& operator=(const Ray& other) = default;

        Ray& operator=(Ray&& other) = default;

        inline rt::maths::Point3 at(double t) const
        {
            return this->origin + t * this->direction;
        }
    };
}
