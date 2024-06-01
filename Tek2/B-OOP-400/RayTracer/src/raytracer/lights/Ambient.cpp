#include "raytracer/lights/Ambient.hpp"

namespace rt::lights {
    Ambient::Ambient(const rt::materials::Color &color, float intensity)
        : _color(color), _intensity(intensity)
    {
    }

    rt::materials::Color Ambient::illuminate(
        [[maybe_unused]] const rt::core::Hit &hit,
        [[maybe_unused]] const rt::objects::IObject& scene
    ) const
    {
        return _color * _intensity;
    }
}
