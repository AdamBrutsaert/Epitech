/*
** EPITECH PROJECT, 2024
** Cylinder.hpp
** File description:
** Cylinder.hpp
*/

#pragma once

#include "IObject.hpp"
#include "raytracer/materials/IMaterial.hpp"

namespace rt::objects {
    class Cylinder : public IObject {
    public:
        Cylinder(
            const rt::maths::Vector3& center,
            float radius,
            std::shared_ptr<rt::materials::IMaterial> material
        );

        ~Cylinder() = default;

        virtual bool hit(
            const rt::core::Ray& ray,
            rt::maths::Interval interval,
            rt::core::Hit& hit
        ) const;

        virtual rt::maths::AABB boundingBox() const;

    private:
        rt::maths::Vector3 _center;
        float _radius;
        std::shared_ptr<rt::materials::IMaterial> _material;
    };
}
