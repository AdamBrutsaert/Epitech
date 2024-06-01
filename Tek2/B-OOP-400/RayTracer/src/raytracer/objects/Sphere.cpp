#include "raytracer/objects/Sphere.hpp"

namespace rt::objects {
    Sphere::Sphere(
        const rt::maths::Point3& center,
        double radius,
        std::shared_ptr<rt::materials::IMaterial> mat
    )
        : _radius(std::fmax(0, radius)), _center(center), _material(mat)
    {
        auto rvec = rt::maths::Vector3(radius, radius, radius);
        this->_bbox = rt::maths::AABB(center - rvec, center + rvec);
    }

    bool Sphere::hit(const rt::core::Ray& r, rt::maths::Interval ray_t, rt::core::Hit& rec) const
    {
        rt::maths::Vector3 oc = this->_center - r.origin;
        auto a = r.direction.lengthSquared();
        auto h = dot(r.direction, oc);
        auto c = oc.lengthSquared() - _radius*_radius;

        auto discriminant = h*h - a*c;
        if (discriminant < 0)
            return false;

        auto sqrtd = sqrt(discriminant);

        auto root = (h - sqrtd) / a;
        if (!ray_t.surrounds(root)) {
            root = (h + sqrtd) / a;
            if (!ray_t.surrounds(root))
                return false;
        }

        rec.t = root;
        rec.point = r.at(rec.t);
        rt::maths::Vector3 outward_normal = (rec.point - _center) / _radius;
        rec.setFaceAndNormal(r, outward_normal);
        rec.material = _material;

        return true;
    }

    rt::maths::AABB Sphere::boundingBox() const
    {
        return this->_bbox;
    }
}
