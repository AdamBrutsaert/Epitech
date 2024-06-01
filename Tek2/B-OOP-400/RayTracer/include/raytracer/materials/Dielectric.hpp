#pragma once

#include "IMaterial.hpp"

namespace rt::materials {
    class Dielectric : public IMaterial {
    public:
        Dielectric(double refractionIndex);
        ~Dielectric() = default;

        virtual bool scatter(
            const rt::core::Ray& ray,
            const rt::core::Hit& hit,
            Color& attenuation,
            rt::core::Ray& scattered
        ) const override;

    private:
        double _refractionIndex;
    };
}
