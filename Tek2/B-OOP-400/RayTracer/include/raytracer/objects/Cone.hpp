/*
** EPITECH PROJECT, 2024
** Cone.hpp
** File description:
** Cone.hpp
*/

#pragma once

#include "IObject.hpp"
#include "raytracer/materials/IMaterial.hpp"

namespace rt::objects {
    class Cone : public IObject {
    public:
        Cone(
            const rt::maths::Vector3& apex,
            float angle,
            std::shared_ptr<rt::materials::IMaterial> material
        );

        ~Cone() = default;

        virtual bool hit(
            const rt::core::Ray& ray,
            rt::maths::Interval interval,
            rt::core::Hit& hit
        ) const;

        virtual rt::maths::AABB boundingBox() const;

    private:
        rt::maths::Vector3 _apex;
        float _angle;
        std::shared_ptr<rt::materials::IMaterial> _material;
    };
}
