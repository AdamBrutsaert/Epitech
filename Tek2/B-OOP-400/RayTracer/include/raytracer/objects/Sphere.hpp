#pragma once

#include "IObject.hpp"
#include "raytracer/materials/IMaterial.hpp"

namespace rt::objects {
    class Sphere : public IObject {
    public:
        Sphere(
            const rt::maths::Point3& center,
            double radius,
            std::shared_ptr<rt::materials::IMaterial> mat
        );

        virtual bool hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const override;
        virtual rt::maths::AABB boundingBox() const override;

    private:
        double _radius;
        rt::maths::Point3 _center;
        std::shared_ptr<rt::materials::IMaterial> _material;
        rt::maths::AABB _bbox;
    };
}
