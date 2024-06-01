#include "raytracer/materials/Lambertian.hpp"

namespace rt::materials {
    Lambertian::Lambertian(const Color& albedo)
        : _albedo(albedo)
    {
    }

    bool Lambertian::scatter(
        [[maybe_unused]] const rt::core::Ray& ray,
        const rt::core::Hit& hit,
        Color& attenuation,
        rt::core::Ray& scattered
    ) const
    {
        auto scatterDirection = hit.normal + rt::maths::Vector3::RandomUnit();

        if (scatterDirection.nearZero())
            scatterDirection = hit.normal;

        scattered = rt::core::Ray(hit.point, scatterDirection);
        attenuation = this->_albedo;
        return true;
    }
}
