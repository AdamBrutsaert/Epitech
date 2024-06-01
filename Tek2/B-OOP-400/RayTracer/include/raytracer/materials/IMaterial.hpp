#pragma once

#include "raytracer/core/Ray.hpp"
#include "raytracer/core/Hit.hpp"
#include "Color.hpp"

namespace rt::materials {
    class IMaterial {
    public:
        virtual ~IMaterial() = default;

        virtual bool scatter(
            const rt::core::Ray& ray,
            const rt::core::Hit& hit,
            Color& attenuation,
            rt::core::Ray& scattered
        ) const = 0;
    };
}
