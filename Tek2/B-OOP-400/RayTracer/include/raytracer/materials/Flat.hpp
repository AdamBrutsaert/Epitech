#pragma once

#include "IMaterial.hpp"

namespace rt::materials {
    class Flat : public IMaterial {
    public:
        Flat(const Color& color);
        ~Flat() = default;

        virtual bool scatter(
            const rt::core::Ray& ray,
            const rt::core::Hit& hit,
            Color& attenuation,
            rt::core::Ray& scattered
        ) const override;

    private:
        Color _color;
    };
}
