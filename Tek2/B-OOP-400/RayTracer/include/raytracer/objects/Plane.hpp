#pragma once

#include "IObject.hpp"
#include "raytracer/materials/IMaterial.hpp"

namespace rt::objects {
    class Plane : public IObject {
    public:
        Plane(
            const rt::maths::Vector3& normal,
            const rt::maths::Vector3& position,
            std::shared_ptr<rt::materials::IMaterial> material
        );

        ~Plane() = default;

        virtual bool hit(
            const rt::core::Ray& ray,
            rt::maths::Interval interval,
            rt::core::Hit& hit
        ) const;

        virtual rt::maths::AABB boundingBox() const;

    private:
        rt::maths::Vector3 _position;
        rt::maths::Vector3 _normal;
        std::shared_ptr<rt::materials::IMaterial> _material;
    };
}
