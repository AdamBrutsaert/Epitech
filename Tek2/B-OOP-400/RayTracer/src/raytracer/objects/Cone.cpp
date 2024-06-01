#include "raytracer/objects/Cone.hpp"

namespace rt::objects {
    Cone::Cone(
        const rt::maths::Vector3& center,
        float angle,
        std::shared_ptr<rt::materials::IMaterial> material
    )
        : _apex(center), _angle(rt::maths::DegreesToRadians(angle)), _material(material)
    {
    }

    bool Cone::hit(
        const rt::core::Ray& ray,
        rt::maths::Interval interval,
        rt::core::Hit& hit
    ) const
    {
        double tanAngle = std::tan(this->_angle);

        double a = ray.direction.x * ray.direction.x
            + ray.direction.y * ray.direction.y
            - ray.direction.z * ray.direction.z * tanAngle * tanAngle;
        double b = 2 * (ray.origin.x * ray.direction.x
            + ray.origin.y * ray.direction.y
            - ray.origin.z * ray.direction.z * tanAngle * tanAngle);
        double c = ray.origin.x * ray.origin.x
            + ray.origin.y * ray.origin.y
            - ray.origin.z * ray.origin.z * tanAngle * tanAngle;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return false;

        double t = (-b - std::sqrt(discriminant)) / (2 * a);
        if (!interval.surrounds(t)) {
            t = (-b + std::sqrt(discriminant)) / (2 * a);
            if (!interval.surrounds(t))
                return false;
        }

        hit.t = t;
        hit.point = ray.at(t);

        // Find the normal vector at the intersection point
        rt::maths::Vector3 normal = rt::maths::Vector3(
            hit.point.x,
            hit.point.y,
            -tanAngle * tanAngle * hit.point.z
        );

        hit.setFaceAndNormal(ray, normalize(normal));
        hit.material = this->_material;

        return true;
    }

    rt::maths::AABB Cone::boundingBox() const
    {
        return rt::maths::AABB{
            rt::maths::Point3{
                -maths::infinity,
                -maths::infinity,
                -maths::infinity
            },
            rt::maths::Point3{
                +maths::infinity,
                +maths::infinity,
                +maths::infinity
            }
        };
    }
}
