#include "raytracer/materials/Flat.hpp"

namespace rt::materials {
    Flat::Flat(const Color& color)
        : _color(color)
    {
    }

    bool Flat::scatter(
        [[maybe_unused]] const rt::core::Ray& ray,
        [[maybe_unused]] const rt::core::Hit& hit,
        Color& attenuation,
        [[maybe_unused]] rt::core::Ray& scattered
    ) const
    {
        attenuation = this->_color;
        return false;
    }
}
