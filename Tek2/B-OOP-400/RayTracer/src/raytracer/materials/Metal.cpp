#include "raytracer/materials/Metal.hpp"

#include <algorithm>

namespace rt::materials {
    Metal::Metal(const Color& albedo, double fuzziness)
        : _albedo(albedo), _fuzziness(std::clamp(fuzziness, 0.0, 1.0))
    {
    }

    bool Metal::scatter(
        const rt::core::Ray& ray,
        const rt::core::Hit& hit,
        Color& attenuation,
        rt::core::Ray& scattered
    ) const
    {
        rt::maths::Vector3 reflected = reflect(ray.direction, hit.normal);
        reflected = normalize(reflected) + (this->_fuzziness * rt::maths::Vector3::RandomUnit());
        scattered = rt::core::Ray(hit.point, reflected);
        attenuation = this->_albedo;
        return (dot(scattered.direction, hit.normal) > 0);
    }
}
