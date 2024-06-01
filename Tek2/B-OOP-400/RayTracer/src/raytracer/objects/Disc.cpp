#include "raytracer/objects/Disc.hpp"

namespace rt::objects {
    Disc::Disc(
        const rt::maths::Vector3& center,
        const rt::maths::Vector3& normal,
        float radius,
        std::shared_ptr<rt::materials::IMaterial> material
    )
        : _center(center), _normal(normal), _radius(radius), _material(material)
    {
    }

    bool Disc::hit(
        const rt::core::Ray& ray,
        rt::maths::Interval interval,
        rt::core::Hit& hit
    ) const
    {
        auto sum = dot(ray.direction, _normal);

        if (sum == 0)
            return false;

        auto t = dot(_center - ray.origin, _normal) / sum;

        if (!interval.contains(t))
            return false;

        auto p = ray.at(t);

        if ((p - _center).lengthSquared() > _radius * _radius)
            return false;

        hit.t = t;
        hit.point = p;
        hit.setFaceAndNormal(ray, sum < 0 ? -_normal : _normal);
        hit.material = _material;

        return true;
    }

    rt::maths::AABB Disc::boundingBox() const
    {
        return rt::maths::AABB(
            maths::Interval(_center.x - _radius, _center.x + _radius),
            maths::Interval(_center.y - _radius, _center.y + _radius),
            maths::Interval(_center.z - _radius, _center.z + _radius)
        );
    }
}
