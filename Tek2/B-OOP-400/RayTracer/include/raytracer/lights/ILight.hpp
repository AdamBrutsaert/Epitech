#pragma once

#include "raytracer/materials/Color.hpp"
#include "raytracer/core/Hit.hpp"
#include "raytracer/objects/IObject.hpp"

namespace rt::lights {
    class ILight {
    public:
        virtual ~ILight() = default;

        virtual rt::materials::Color illuminate(
            const rt::core::Hit& hit,
            const rt::objects::IObject& scene
        ) const = 0;
    };
}
