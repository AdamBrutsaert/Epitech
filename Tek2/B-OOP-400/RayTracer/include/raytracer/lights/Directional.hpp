/*
** EPITECH PROJECT, 2024
** Directional.hpp
** File description:
** Directional.hpp
*/

#pragma once

#include "ILight.hpp"

namespace rt::lights {
    class Directional : public ILight {
    public:
        Directional(rt::maths::Vector3 direction, const rt::materials::Color &color, float intensity);
        ~Directional() = default;

        rt::materials::Color illuminate(
            const rt::core::Hit &hit,
            const rt::objects::IObject& scene
        ) const override;

    private:
        rt::maths::Vector3 _direction;
        rt::materials::Color _color;
        float _intensity;
    };
}
