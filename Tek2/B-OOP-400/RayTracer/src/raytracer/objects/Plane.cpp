/*
** EPITECH PROJECT, 2024
** Plane.cpp
** File description:
** Plane.cpp
*/

#include "raytracer/objects/Plane.hpp"

namespace rt::objects {
    Plane::Plane(
        const rt::maths::Vector3& normal,
        const rt::maths::Vector3& position,
        std::shared_ptr<rt::materials::IMaterial> material
    )
        : _position(position), _normal(normal), _material(material)
    {
    }

   bool Plane::hit(
        const rt::core::Ray& ray,
        rt::maths::Interval interval,
        rt::core::Hit& hit
    ) const
    {
        auto sum = dot(ray.direction, _normal);

        if (sum == 0)
            return false;

        auto t = dot(_position - ray.origin, _normal) / sum;

        if (!interval.contains(t))
            return false;

        auto p = ray.at(t);

        hit.t = t;
        hit.point = p;
        hit.setFaceAndNormal(ray, sum < 0 ? -this->_normal : this->_normal);
        hit.material = this->_material;

        return true;
    }

    rt::maths::AABB Plane::boundingBox() const
    {
        return rt::maths::AABB(
            maths::Interval::Universe,
            maths::Interval::Universe,
            maths::Interval::Universe
        );
    }
}
