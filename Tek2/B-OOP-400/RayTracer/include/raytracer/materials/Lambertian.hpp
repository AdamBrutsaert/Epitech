#pragma once

#include "IMaterial.hpp"

namespace rt::materials {
    class Lambertian : public IMaterial {
    public:
        Lambertian(const Color& albedo);
        ~Lambertian() = default;

        virtual bool scatter(
            const rt::core::Ray& ray,
            const rt::core::Hit& hit,
            Color& attenuation,
            rt::core::Ray& scattered
        ) const override;

    private:
        Color _albedo;
    };
}
