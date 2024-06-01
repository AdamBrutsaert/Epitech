#pragma once

#include "IMaterial.hpp"

namespace rt::materials {
    class Metal : public IMaterial {
    public:
        Metal(const Color& albedo, double fuzziness);
        ~Metal() = default;

        virtual bool scatter(
            const rt::core::Ray& ray,
            const rt::core::Hit& hit,
            Color& attenuation,
            rt::core::Ray& scattered
        ) const override;

    private:
        Color _albedo;
        double _fuzziness;
    };
}
