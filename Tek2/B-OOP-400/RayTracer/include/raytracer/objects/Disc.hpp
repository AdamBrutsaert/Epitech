/*
** EPITECH PROJECT, 2024
** Disc.hpp
** File description:
** Disc.hpp
*/

#pragma once

#include "IObject.hpp"
#include "raytracer/materials/IMaterial.hpp"

namespace rt::objects {
    class Disc : public IObject {
    public:
        Disc(
            const rt::maths::Vector3& center,
            const rt::maths::Vector3& normal,
            float radius,
            std::shared_ptr<rt::materials::IMaterial> material
        );

        ~Disc() = default;

        virtual bool hit(
            const rt::core::Ray& ray,
            rt::maths::Interval interval,
            rt::core::Hit& hit
        ) const;

        virtual rt::maths::AABB boundingBox() const;

    private:
        rt::maths::Vector3 _center;
        rt::maths::Vector3 _normal;
        float _radius;
        std::shared_ptr<rt::materials::IMaterial> _material;
    };
}
