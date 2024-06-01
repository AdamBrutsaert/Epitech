#include "raytracer/materials/Dielectric.hpp"

namespace rt::materials {
    Dielectric::Dielectric(double refractionIndex)
        : _refractionIndex(refractionIndex)
    {
    }

    static double Reflectance(double cosine, double refractionIndex)
    {
        auto r0 = (1 - refractionIndex) / (1 + refractionIndex);
        r0 = r0*r0;
        return r0 + (1-r0)*pow((1 - cosine),5);
    }

    bool Dielectric::scatter(
        const rt::core::Ray& ray,
        const rt::core::Hit& hit,
        Color& attenuation,
        rt::core::Ray& scattered
    ) const
    {
        attenuation = Color(1.0, 1.0, 1.0);
        double ri = hit.frontFace ? (1.0 / this->_refractionIndex) : this->_refractionIndex;

        rt::maths::Vector3 unit_direction = normalize(ray.direction);
        double cos_theta = fmin(dot(-unit_direction, hit.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

        bool cannot_refract = ri * sin_theta > 1.0;
        rt::maths::Vector3 direction;

        if (cannot_refract || Reflectance(cos_theta, ri) > rt::maths::RandomDouble())
            direction = reflect(unit_direction, hit.normal);
        else
            direction = refract(unit_direction, hit.normal, ri);

        scattered = rt::core::Ray(hit.point, direction);
        return true;
    }
}
