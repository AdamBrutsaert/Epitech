#pragma once

#include "raytracer/maths/Vector3.hpp"
#include "Ray.hpp"

#include <memory>

namespace rt::materials {
    class IMaterial;
}

namespace rt::core {
    class Hit {
    public:
        rt::maths::Point3 point;
        rt::maths::Vector3 normal;
        std::shared_ptr<rt::materials::IMaterial> material;
        double t;
        bool frontFace;

        inline void setFaceAndNormal(const rt::core::Ray& r, const rt::maths::Vector3& normal)
        {
            this->frontFace = dot(r.direction, normal) < 0;
            this->normal = this->frontFace ? normal : -normal;
        }
    };
}
