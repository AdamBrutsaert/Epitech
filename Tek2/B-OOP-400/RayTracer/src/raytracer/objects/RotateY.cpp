#include "raytracer/objects/RotateY.hpp"

namespace rt::objects {
    RotateY::RotateY(std::shared_ptr<IObject> object, double angle)
        : _object(object)
    {
        auto radians = rt::maths::DegreesToRadians(angle);
        this->_sin_theta = std::sin(radians);
        this->_cos_theta = std::cos(radians);
        this->_bbox = this->_object->boundingBox();

        rt::maths::Vector3 min(rt::maths::infinity, rt::maths::infinity, rt::maths::infinity);
        rt::maths::Vector3 max(-rt::maths::infinity, -rt::maths::infinity, -rt::maths::infinity);

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    auto x = i * this->_bbox.x.max + (1 - i) * this->_bbox.x.min;
                    auto y = j * this->_bbox.y.max + (1 - j) * this->_bbox.y.min;
                    auto z = k * this->_bbox.z.max + (1 - k) * this->_bbox.z.min;

                    auto newX = this->_cos_theta * x + this->_sin_theta * z;
                    auto newZ = -this->_sin_theta * x + this->_cos_theta * z;

                    rt::maths::Vector3 tester(newX, y, newZ);

                    for (int c = 0; c < 3; c++) {
                        min[c] = std::min(min[c], tester[c]);
                        max[c] = std::max(max[c], tester[c]);
                    }
                }
            }
        }

        this->_bbox = rt::maths::AABB(min, max);
    }

    bool RotateY::hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const
    {
        auto origin = r.origin;
        auto direction = r.direction;

        origin[0] = this->_cos_theta * r.origin[0] - this->_sin_theta * r.origin[2];
        origin[2] = this->_sin_theta * r.origin[0] + this->_cos_theta * r.origin[2];

        direction[0] = this->_cos_theta * r.direction[0] - this->_sin_theta * r.direction[2];
        direction[2] = this->_sin_theta * r.direction[0] + this->_cos_theta * r.direction[2];

        rt::core::Ray rotatedRay(origin, direction);

        if (!this->_object->hit(rotatedRay, ray_t, rec))
            return false;

        auto p = rec.point;
        p[0] = this->_cos_theta * rec.point[0] + this->_sin_theta * rec.point[2];
        p[2] = -this->_sin_theta * rec.point[0] + this->_cos_theta * rec.point[2];

        auto normal = rec.normal;
        normal[0] = this->_cos_theta * rec.normal[0] + this->_sin_theta * rec.normal[2];
        normal[2] = -this->_sin_theta * rec.normal[0] + this->_cos_theta * rec.normal[2];

        rec.point = p;
        rec.normal = normal;

        return true;
    }

    rt::maths::AABB RotateY::boundingBox() const
    {
        return this->_bbox;
    }
}
