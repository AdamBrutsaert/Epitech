#include "raytracer/lights/Directional.hpp"

namespace rt::lights {
    Directional::Directional(rt::maths::Vector3 direction, const rt::materials::Color &color, float intensity)
        : _direction(-direction), _color(color), _intensity(intensity)
    {
    }

    rt::materials::Color Directional::illuminate(
        const rt::core::Hit &hit,
        const rt::objects::IObject& scene
    ) const
    {
        // Check if there is nothing intersecting the light
        rt::core::Hit shadowHit;
        rt::maths::Interval shadowInterval(0.001, std::numeric_limits<float>::infinity());

        rt::core::Ray shadowRay(hit.point, this->_direction);
        if (scene.hit(shadowRay, shadowInterval, shadowHit))
            return rt::materials::Color(0, 0, 0);

        return std::fmax(rt::maths::dot(hit.normal, this->_direction), 0) * _color * _intensity;
    }
}
