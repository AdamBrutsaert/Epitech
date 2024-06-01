/*
** EPITECH PROJECT, 2024
** Ambient.hpp
** File description:
** Ambient.hpp
*/

#pragma once

#include "ILight.hpp"

namespace rt::lights {
    class Ambient : public ILight {
    public:
        Ambient(const rt::materials::Color &color, float intensity);
        ~Ambient() = default;

        rt::materials::Color illuminate(
            const rt::core::Hit &hit,
            const rt::objects::IObject& scene
        ) const override;

    private:
        rt::materials::Color _color;
        float _intensity;
    };
}
