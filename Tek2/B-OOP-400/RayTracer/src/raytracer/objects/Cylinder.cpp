#include "raytracer/objects/Cylinder.hpp"

namespace rt::objects {
    Cylinder::Cylinder(
        const rt::maths::Vector3& center,
        float radius,
        std::shared_ptr<rt::materials::IMaterial> material
    )
        : _center(center), _radius(radius), _material(material)
    {
    }

    bool Cylinder::hit(
        const rt::core::Ray& ray,
        rt::maths::Interval interval,
        rt::core::Hit& hit
    ) const
    {
        maths::Point3 oc = maths::Point3{
            ray.origin.x - _center.x,
            ray.origin.y - _center.y,
            0
        };

        double a = ray.direction.x * ray.direction.x + ray.direction.y * ray.direction.y;
        double b = 2 * (oc.x * ray.direction.x + oc.y * ray.direction.y);
        double c = oc.x * oc.x + oc.y * oc.y - _radius * _radius;

        double discriminant = b * b - 4 * a * c;

        if (discriminant < 0)
            return false;

        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);
        double t = std::fmin(t1, t2);

        if (!interval.surrounds(t))
            return false;

        hit.t = t;
        hit.point = ray.at(t);
        hit.material = _material;

        rt::maths::Vector3 normal = normalize(rt::maths::Vector3{
            hit.point.x - _center.x,
            hit.point.y - _center.y,
            0
        });

        hit.setFaceAndNormal(ray, normal);

        return true;
    }

    rt::maths::AABB Cylinder::boundingBox() const
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
